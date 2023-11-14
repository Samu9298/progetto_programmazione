#include "../Header files/AccountView.h"

AccountView::AccountView(Model *model, Controller *controller) : {
    this->model = model;
    this->model->registerModelObserver(this);
    this->controller = controller;
}

AccountView::~AccountView() {
    this->model->removeModelObserver(this);
}

void AccountView::update() {

}
