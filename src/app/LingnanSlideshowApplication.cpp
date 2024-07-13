#include "LingnanSlideshowApplication.h"
#include "OpenBookTasks.h"
#include "OpenBookEvents.h"

void LingnanSlideshowApplication::setup() {
    // set up tasks for button input and display
    std::shared_ptr<Task> inputTask = std::make_shared<OpenBookRawButtonInput>();
    this->addTask(inputTask);
    std::shared_ptr<Task> lingnanTask = std::make_shared<LingnanAutoAdvance>();
    this->addTask(lingnanTask);
    std::shared_ptr<Task> displayTask = std::make_shared<OpenBookDisplay>();
    this->addTask(displayTask);

    this->mainMenu = std::make_shared<LingnanSlideshowViewController>(this->shared_from_this());
    this->setRootViewController(this->mainMenu);
}
