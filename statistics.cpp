#include "statistics.h"
#include "ui_statistics.h"

statistics::statistics(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statistics)
{
    ui->setupUi(this);
        //The QPieSeries class presents data in pie charts
            QPieSeries *series=new QPieSeries();
            //The QLineSeries class presents data in line charts.
              series->append("[Jazz]",mscs.stat_mus(1));
              series->append("[Electro]",mscs.stat_mus(2));
              series->append("[Traditional]",mscs.stat_mus(3));
              series->append("[Rock]",mscs.stat_mus(4));
              series->append("[Classical]",mscs.stat_mus(5));

              //The QPieSlice class represents a single slice in a pie series
              QPieSlice *slice1=series->slices().at(1);
              slice1->setExploded(true);

              QChart *chart =new QChart();
              chart->addSeries(series);
              chart->setTitle("Musicians by genre");
              chart->setAnimationOptions(QChart::AllAnimations);
              QChartView *chartview=new QChartView(chart);
              this->setCentralWidget(chartview);
}

statistics::~statistics()
{
    delete ui;
}
