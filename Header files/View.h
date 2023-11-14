#ifndef PROGETTO_PROGRAMMAZIONE_VIEW_H
#define PROGETTO_PROGRAMMAZIONE_VIEW_H

class View {
public:
    virtual ~View() {};
    virtual void update() = 0;
};

#endif //PROGETTO_PROGRAMMAZIONE_VIEW_H
