#ifndef MODELSUBSCRIBER_H
#define MODELSUBSCRIBER_H

namespace map_editor
{
    class ModelSubscriber;
    class Index;
}
class map_editor::ModelSubscriber
{
public:
    virtual void platformAdded(const map_editor::Index& index);
    virtual void platformDeleted(const map_editor::Index& index);
    virtual void platformUpdated(const map_editor::Index& index);

    virtual void indexSelected(const map_editor::Index& index);
};

#endif // MODELSUBSCRIBER_H
