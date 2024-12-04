#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QVector>
#include <QMap>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void onLoadFromFile(const QString& filePath);
    QString result;
    QStringList pathStringList;
    int totalWeight;

protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void onAddEdge();
    void onFindShortestPath();
    void onToggleWeightSign();
    double calculateEuclideanDistance(const QPointF& p1, const QPointF& p2);
    void onExportToFile();
    void onCaptureMap();





private:
    struct Vertex {
        QPointF position;
        QChar label;
        QGraphicsEllipseItem *ellipseItem; // Thêm item đồ họa vào đây
        QList<QPair<QString, int>> edges;
        QChar vertexName;
    };

    struct Edge {
        QChar from;
        QChar to;
        int weight;
    };

    QMap<QChar, Vertex> verticesMap; // Lưu thông tin các đỉnh
    QVector<Edge> edges;  // Danh sách các cạnh
    QGraphicsScene *scene;
    QGraphicsView *view;
    QPushButton *addEdgeButton;
    QList<QGraphicsLineItem*> shortestPathLines;
    QChar vertexCounter;
    QList<QGraphicsEllipseItem*> coloredVertices;
    QList<QGraphicsLineItem*> coloredEdges;
    QPushButton *toggleWeightSignButton;
    QString exportFilePath;

};

#endif // MAINWINDOW_H
