#ifndef LingnanSlideshowViewController_h
#define LingnanSlideshowViewController_h

#include "Focus.h"
#include "FocusWidgets.h"
#include "OpenBookWidgets.h"

class LingnanSlideshowViewController : public ViewController {
public:
    LingnanSlideshowViewController(std::shared_ptr<Application> application) : ViewController(application) {};
    void switchImage(Event event);
protected:
    virtual void createView() override;
private:
    std::shared_ptr<BitmapView> imageView;
    int32_t imageIndex = 0;
};

#endif // LingnanSlideshowViewController_h
