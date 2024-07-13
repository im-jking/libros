import os
from PIL import Image

def convert_png_to_bytearray(file_path):
    image = Image.open(file_path)
    image = image.convert("1")
    image = image.point(lambda p: p == 0) # invert it
    byte_array = bytearray()
    for i in range(0, image.height):
        for j in range(0, image.width, 8):
            byte = 0
            for k in range(0, 8):
                if j + k < image.width and image.getpixel((j + k, i)):
                    byte |= 1 << (7 - k)
            byte_array.append(byte)
    return byte_array

def convert_png_to_c_style_array(file_path):
    file_name = file_path.split("/")[-1].split(".")[0]
    retval = f"const unsigned char _{file_name}[] = {{\n    "
    byte_array = convert_png_to_bytearray(file_path)
    for i in range(0, len(byte_array), 38):
        retval += ", ".join("0x{:02x}".format(byte) for byte in byte_array[i:i+38]) + ",\n    "
    retval = retval[:-4] + "};"

    return retval

# convert all PNG files in the folder
folder_path = "./book_00/"
files = os.listdir(folder_path)
files.sort()
filenames = []
for file in files:
    if file.endswith(".jpg"):
        filenames.append(f"_{file.split(".")[0]}")
        file_path = folder_path + file
        print(convert_png_to_c_style_array(file_path))
        print("\n")

print("const uint8_t *all_artwork[] = {")
for filename in filenames:
    print(f"    {filename},")
print("};")
