#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QVector>
#include <QScrollBar>
#include <QDebug>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class point3D
{
public:
	int x;
	int y;
	int z;
};

class Cube
{
public:
	QVector<QVector<point3D>> faces;
	QVector<QColor> color;
};

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	void paintEvent(QPaintEvent *);
	void verF(int value);
	void horF(int value);
	void R();
	void R_();
	void U();
	void U_();
	void F();
	void F_();
	void L();
	void L_();
	void D();
	void D_();
	void B();
	void B_();
private:
	Ui::MainWindow *ui;
	QVector<QVector<QVector<Cube>>> cube;
	int horC = 0;
	int verC = 0;
	int hor = 15;
	int ver = 15;
	int length = 100;
	int rot = 0;
};


#endif // MAINWINDOW_H
