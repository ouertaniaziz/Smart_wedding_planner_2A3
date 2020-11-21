#include "mydelegate.h"

void ItemDelegatePaint::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
       QString txt = index.model()->data( index, Qt::DisplayRole ).toString();

       if(index.row() == 0)//green row
           painter->fillRect(option.rect,QColor(0,255,0));
       else
           if(index.row() == 1)//blue row
               painter->fillRect(option.rect,QColor(0,0,255));
       else
           if(index.row() == 2)//red row
               painter->fillRect(option.rect,QColor(255,0,0));
       //and so on

       if( option.state & QStyle::State_Selected )//we need this to show selection
       {
           painter->fillRect( option.rect, option.palette.highlight() );
       }


       QStyledItemDelegate::paint(painter,option,index);//standard processing
}
