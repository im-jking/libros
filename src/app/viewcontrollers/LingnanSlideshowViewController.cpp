#include "LingnanSlideshowViewController.h"
#include "OpenBookEvents.h"
#include "bitmaps.h"
#include "OpenBookTasks.h"
#include "OpenBookDevice.h"

#include "../../../utility/all-artwork/book_10.c"

void LingnanSlideshowViewController::createView() {
    ViewController::createView();
    this->view = std::make_shared<Control>(MakeRect(0, 0, 300, 400));
    this->view->setOpaque(true);
    this->view->setBackgroundColor(EPD_DARK);
    this->imageView = std::make_shared<BitmapView>(MakeRect(0, 0, 300, 400), all_artwork[0]);
    this->imageView->setOpaque(true);
    this->view->setAction(std::bind(&LingnanSlideshowViewController::switchImage, this, std::placeholders::_1), FOCUS_EVENT_BUTTON_NEXT);
    this->view->setAction(std::bind(&LingnanSlideshowViewController::switchImage, this, std::placeholders::_1), FOCUS_EVENT_BUTTON_PREV);
    this->view->addSubview(imageView);
}

void LingnanSlideshowViewController::switchImage(Event event) {
    if (event.type == FOCUS_EVENT_BUTTON_NEXT) {
        // advance to next image, wrapping around to the first image if necessary
        this->imageIndex = (this->imageIndex + 1) % (sizeof(all_artwork) / sizeof(all_artwork[0]));
    } else if (event.type == FOCUS_EVENT_BUTTON_PREV) {
        // don't change the image if the current image is the first one
        if (this->imageIndex == 0) {
            return;
        }
        this->imageIndex--;
    }

    this->view->removeSubview(this->imageView);
    this->imageView = std::make_shared<BitmapView>(MakeRect(0, 0, 300, 400), all_artwork[this->imageIndex]);
    this->imageView->setOpaque(true);
    this->view->setAction(std::bind(&LingnanSlideshowViewController::switchImage, this, std::placeholders::_1), FOCUS_EVENT_BUTTON_NEXT);
    this->view->setAction(std::bind(&LingnanSlideshowViewController::switchImage, this, std::placeholders::_1), FOCUS_EVENT_BUTTON_PREV);
    this->view->addSubview(imageView);
}
