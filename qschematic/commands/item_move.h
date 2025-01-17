#pragma once

#include "base.h"

#include <QVector>
#include <QVector2D>

#include <memory>

class QVector2D;

namespace QSchematic::Items
{
    class Item;
}

namespace QSchematic::Commands
{

    class ItemMove :
        public Base
    {
    public:
        ItemMove(
            const QVector<std::shared_ptr<Items::Item>>& item,
            QVector2D moveBy,
            QUndoCommand* parent = nullptr
        );

        int id() const override;
        bool mergeWith(const QUndoCommand* command) override;
        void undo() override;
        void redo() override;

    private:
        QVector<std::shared_ptr<Items::Item>> _items;
        QVector2D _moveBy;

        void
        simplifyWires() const;
    };

}
