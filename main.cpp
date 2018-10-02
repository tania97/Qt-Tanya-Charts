#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalPercentBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*
     * -----Pie chart------
    QPieSeries *series = new QPieSeries(); //define data
    series->append("Potatos", 40);
    series->append("Tomatos", 20);
    series->append("Apples", 15);
    series->append("Lemons", 10);
    series->append("Zuccinis", 15);

    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();

    QPieSlice *slice1 = series->slices().at(1);
    slice0->setExploded();
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::green);

    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible();

    QPieSlice *slice3 = series->slices().at(3);
    slice3->setLabelVisible();

    QPieSlice *slice4 = series->slices().at(4);
    slice4->setLabelVisible();

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Ewa chart");
    chart->legend()->hide();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    */

    /* ---line graph----
    QLineSeries *series = new QLineSeries();
    series->append(0,16);
    series->append(1,10);
    series->append(2,30);
    series->append(3,22);
    series->append(4,16);
    series->append(5,27);
    series->append(6,34);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();

    QFont font;
    font.setPixelSize(19);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::black));
    chart->setTitle("Tanyas graph dope stuff ja man");

    QPen pen(QRgb(0x000000));
    pen.setWidth(5);
    series->setPen(pen);

    chart->setAnimationOptions(QChart::AllAnimations);
    QCategoryAxis *axisX = new QCategoryAxis();
    axisX->append("1986",0);
    axisX->append("1987",1);
    axisX->append("1988",2);
    axisX->append("1989",3);
    axisX->append("1990",4);
    axisX->append("1991",5);
    axisX->append("1992",6);

    chart->setAxisX(axisX, series);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    **/
    /* ------Bar graph----- */
    QBarSet *set0 = new QBarSet("Tanya");
    QBarSet *set1 = new QBarSet("Maja");
    QBarSet *set2 = new QBarSet("Suzanne");
    QBarSet *set3 = new QBarSet("Shannon");
    QBarSet *set4 = new QBarSet("Inna");

    *set0 << 283 << 341 << 313 << 338 << 346 <<335;
    *set1 << 250 << 281 << 233 << 310 << 346 <<330;
    *set2 << 294 << 282 << 295 << 302 << 346 <<315;
    *set3 << 248 << 314 << 310 << 326 << 298 <<322;
    *set4 << 323 << 268 << 299 << 307 << 301 <<335;

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Tanya Title Avg");
    chart->setAnimationOptions(QChart::AllAnimations);

    QStringList categories;
    categories << "2013" << "2014"<< "2015" << "2016"<< "2017" << "2018";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    qApp->setPalette(pal);


    QMainWindow w;
    w.setCentralWidget(chartView);
    w.resize(420, 300);
    w.show();

    return a.exec();
}
