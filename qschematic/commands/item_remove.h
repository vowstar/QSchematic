#pragma once

#include "base.h"

#include <QPointer>

#include <memory>

class QGraphicsItem;

namespace QSchematic
{
    class Scene;
}

namespace QSchematic::Items
{
    class Item;
}

namespace QSchematic::Commands
{

    class ItemRemove :
        public Base
    {
    public:
        ItemRemove(const QPointer<Scene>& scene, const std::shared_ptr<Items::Item>& item, QUndoCommand* parent = nullptr);

        int id() const override;
        bool mergeWith(const QUndoCommand* command) override;
        void undo() override;
        void redo() override;

    private:
        QPointer<Scene> _scene;
        std::shared_ptr<Items::Item> _item;
        QGraphicsItem* _itemParent;
    };

}
