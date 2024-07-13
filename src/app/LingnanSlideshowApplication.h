#ifndef LingnanSlideshowApplication_h
#define LingnanSlideshowApplication_h

#include "Focus.h"
#include "OpenBookDatabase.h"
#include "OpenBookWidgets.h"
#include "LingnanSlideshowViewController.h"
#include <memory>

class LingnanSlideshowApplication : public Application {
public:
    LingnanSlideshowApplication(const std::shared_ptr<Window>& window) : Application(window) {};
    void setup() override;
    std::shared_ptr<LingnanSlideshowViewController> mainMenu;
};

#endif // LingnanSlideshowApplication_h
