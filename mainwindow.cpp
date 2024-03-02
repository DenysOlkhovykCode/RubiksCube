#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	QScrollBar *verticalScrollBar = new QScrollBar(Qt::Vertical, this);
	QScrollBar *horizontalScrollBar = new QScrollBar(Qt::Horizontal, this);
	QPushButton *R = new QPushButton("R ",this);
	QPushButton *R_ =new QPushButton("R_",this);
	QPushButton *U = new QPushButton("U ",this);
	QPushButton *U_ =new QPushButton("U_",this);
	QPushButton *F = new QPushButton("F ",this);
	QPushButton *F_ =new QPushButton("F_",this);
	QPushButton *L = new QPushButton("L ",this);
	QPushButton *L_ =new QPushButton("L_",this);
	QPushButton *D = new QPushButton("D ",this);
	QPushButton *D_ =new QPushButton("D_",this);
	QPushButton *B = new QPushButton("B ",this);
	QPushButton *B_ =new QPushButton("B_",this);

	verticalScrollBar->setMinimum(-360);
	verticalScrollBar->setMaximum(360);
	verticalScrollBar->setGeometry(1170, 0, 30, 1170);
	verticalScrollBar->show();

	horizontalScrollBar->setMinimum(-360);
	horizontalScrollBar->setMaximum(360);
	horizontalScrollBar->setGeometry(0, 1170, 1170, 30);
	horizontalScrollBar->show();

	R ->setGeometry(10,10,40,40);
	R_->setGeometry(50,10,40,40);
	U ->setGeometry(10,50,40,40);
	U_->setGeometry(50,50,40,40);
	F ->setGeometry(10,90,40,40);
	F_->setGeometry(50,90,40,40);
	L ->setGeometry(120,10,40,40);
	L_->setGeometry(160,10,40,40);
	D ->setGeometry(120,50,40,40);
	D_->setGeometry(160,50,40,40);
	B ->setGeometry(120,90,40,40);
	B_->setGeometry(160,90,40,40);

	this->connect(verticalScrollBar, &QScrollBar::sliderMoved, this, &MainWindow::verF);
	this->connect(horizontalScrollBar, &QScrollBar::valueChanged, this, &MainWindow::horF);
	this->connect(R , &QPushButton::clicked, this, &MainWindow::R );
	this->connect(R_, &QPushButton::clicked, this, &MainWindow::R_);
	this->connect(U , &QPushButton::clicked, this, &MainWindow::U );
	this->connect(U_, &QPushButton::clicked, this, &MainWindow::U_);
	this->connect(F , &QPushButton::clicked, this, &MainWindow::F );
	this->connect(F_, &QPushButton::clicked, this, &MainWindow::F_);
	this->connect(L , &QPushButton::clicked, this, &MainWindow::L );
	this->connect(L_, &QPushButton::clicked, this, &MainWindow::L_);
	this->connect(D , &QPushButton::clicked, this, &MainWindow::D );
	this->connect(D_, &QPushButton::clicked, this, &MainWindow::D_);
	this->connect(B , &QPushButton::clicked, this, &MainWindow::B );
	this->connect(B_, &QPushButton::clicked, this, &MainWindow::B_);

	cube.resize(3);
	for (int i = 0; i < 3; ++i) {
		cube[i].resize(3);
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cube[i][j].resize(3);
		}
	}
	for (int g = 0; g < 3; ++g) {
		for (int b = 0; b < 3; ++b) {
			for (int v = 0; v < 3; ++v) {
				cube[g][b][v].color.resize(6);
				cube[g][b][v].faces.resize(6);
				for (int i = 0; i < 6; ++i) {
					cube[g][b][v].faces[i].resize(4);
				}
				cube[g][b][v].faces[0][0].x = 110*g+0;
				cube[g][b][v].faces[0][0].y = 110*b+length;
				cube[g][b][v].faces[0][0].z = 110*v+0;

				cube[g][b][v].faces[0][1].x = 110*g+length;
				cube[g][b][v].faces[0][1].y = 110*b+length;
				cube[g][b][v].faces[0][1].z = 110*v+0;

				cube[g][b][v].faces[0][2].x = 110*g+length;
				cube[g][b][v].faces[0][2].y = 110*b+length;
				cube[g][b][v].faces[0][2].z = 110*v+length;

				cube[g][b][v].faces[0][3].x = 110*g+0;
				cube[g][b][v].faces[0][3].y = 110*b+length;
				cube[g][b][v].faces[0][3].z = 110*v+length;
				if(b==2)
					cube[g][b][v].color[0] = QColor(255,255,0);

				cube[g][b][v].faces[1][0].x = 110*g+0;
				cube[g][b][v].faces[1][0].y = 110*b+0;
				cube[g][b][v].faces[1][0].z = 110*v+0;

				cube[g][b][v].faces[1][1].x = 110*g+length;
				cube[g][b][v].faces[1][1].y = 110*b+0;
				cube[g][b][v].faces[1][1].z = 110*v+0;

				cube[g][b][v].faces[1][2].x = 110*g+length;
				cube[g][b][v].faces[1][2].y = 110*b+0;
				cube[g][b][v].faces[1][2].z = 110*v+length;

				cube[g][b][v].faces[1][3].x = 110*g+0;
				cube[g][b][v].faces[1][3].y = 110*b+0;
				cube[g][b][v].faces[1][3].z = 110*v+length;
				if(b==0)
					cube[g][b][v].color[1] = QColor(255,255,255);

				cube[g][b][v].faces[2][0].x = 110*g+0;
				cube[g][b][v].faces[2][0].y = 110*b+length;
				cube[g][b][v].faces[2][0].z = 110*v+0;

				cube[g][b][v].faces[2][1].x = 110*g+length;
				cube[g][b][v].faces[2][1].y = 110*b+length;
				cube[g][b][v].faces[2][1].z = 110*v+0;

				cube[g][b][v].faces[2][2].x = 110*g+length;
				cube[g][b][v].faces[2][2].y = 110*b+0;
				cube[g][b][v].faces[2][2].z = 110*v+0;

				cube[g][b][v].faces[2][3].x = 110*g+0;
				cube[g][b][v].faces[2][3].y = 110*b+0;
				cube[g][b][v].faces[2][3].z = 110*v+0;
				if(v==0)
					cube[g][b][v].color[2] = QColor(0,255,0);

				cube[g][b][v].faces[3][0].x = 110*g+length;
				cube[g][b][v].faces[3][0].y = 110*b+length;
				cube[g][b][v].faces[3][0].z = 110*v+0;

				cube[g][b][v].faces[3][1].x = 110*g+length;
				cube[g][b][v].faces[3][1].y = 110*b+length;
				cube[g][b][v].faces[3][1].z = 110*v+length;

				cube[g][b][v].faces[3][2].x = 110*g+length;
				cube[g][b][v].faces[3][2].y = 110*b+0;
				cube[g][b][v].faces[3][2].z = 110*v+length;

				cube[g][b][v].faces[3][3].x = 110*g+length;
				cube[g][b][v].faces[3][3].y = 110*b+0;
				cube[g][b][v].faces[3][3].z = 110*v+0;
				if(g==2)
					cube[g][b][v].color[3] = QColor(255,0,0);

				cube[g][b][v].faces[4][0].x = 110*g+0;
				cube[g][b][v].faces[4][0].y = 110*b+length;
				cube[g][b][v].faces[4][0].z = 110*v+0;

				cube[g][b][v].faces[4][1].x = 110*g+0;
				cube[g][b][v].faces[4][1].y = 110*b+length;
				cube[g][b][v].faces[4][1].z = 110*v+length;

				cube[g][b][v].faces[4][2].x = 110*g+0;
				cube[g][b][v].faces[4][2].y = 110*b+0;
				cube[g][b][v].faces[4][2].z = 110*v+length;

				cube[g][b][v].faces[4][3].x = 110*g+0;
				cube[g][b][v].faces[4][3].y = 110*b+0;
				cube[g][b][v].faces[4][3].z = 110*v+0;
				if(g==0)
					cube[g][b][v].color[4] = QColor(255,140,0);

				cube[g][b][v].faces[5][0].x = 110*g+length;
				cube[g][b][v].faces[5][0].y = 110*b+length;
				cube[g][b][v].faces[5][0].z = 110*v+length;

				cube[g][b][v].faces[5][1].x = 110*g+0;
				cube[g][b][v].faces[5][1].y = 110*b+length;
				cube[g][b][v].faces[5][1].z = 110*v+length;

				cube[g][b][v].faces[5][2].x = 110*g+0;
				cube[g][b][v].faces[5][2].y = 110*b+0;
				cube[g][b][v].faces[5][2].z = 110*v+length;

				cube[g][b][v].faces[5][3].x = 110*g+length;
				cube[g][b][v].faces[5][3].y = 110*b+0;
				cube[g][b][v].faces[5][3].z = 110*v+length;
				if(v==2)
					cube[g][b][v].color[5] = QColor(0,0,255);
			}
		}
	}
}

void MainWindow::verF(int value)
{
	verC = ver - value;
	ver = value;
	horC = 0;
	update(); // Перемалювати вікно
}

void MainWindow::horF(int value)
{
	horC = hor - value;
	hor = value;
	verC = 0;
	update(); //Перемалювати вікно
}

void MainWindow::R()
{
	QVector<QVector<QVector<Cube>>> slidecube = cube;
	float slide2 = 0;
	for (int slide = 0 ; slide < 91; ++slide) {
		QTransform transform;
		if(slide<90)
		{
			transform.translate(slide*3.555,slide2);
		}
		else
		{
			transform.translate(slide*3.555,0);
		}
		transform.rotate(slide);
		for (int b = 0; b < 3; ++b) {
			for (int v = 0; v < 3; ++v) {
				for (int i = 0; i < 6; ++i) {
					for (int j = 0; j < 4; ++j) {
						QPoint temp(cube[2][b][v].faces[i][j].y, cube[2][b][v].faces[i][j].z);
						temp = transform.map(temp);
						cube[2][b][v].faces[i][j].y = temp.x();
						cube[2][b][v].faces[i][j].z = temp.y();
					}
				}
			}
		}
		transform.reset();
		repaint();
		if(slide<90)
		{
			cube = slidecube;
		}
		if(slide<46)
		{
			slide2-=1.555555;
		}
		else
		{
			slide2+=1.555555;
		}
	}

	auto temp = cube[2];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp[3 - 1 - j][i] = cube[2][i][j];
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cube[2][i][j] = temp[i][j];
		}
	}
}

void MainWindow::R_()
{
	QVector<QVector<QVector<Cube>>> slidecube = cube;
	float slide2 = 0;
	for (int slide = 0 ; slide < 91; ++slide) {
		QTransform transform;
		if(slide<90)
		{
			transform.translate(slide2,slide*3.555);
		}
		else
		{
			transform.translate(0,slide*3.555);
		}
		transform.rotate(-slide);
		for (int b = 0; b < 3; ++b) {
			for (int v = 0; v < 3; ++v) {
				for (int i = 0; i < 6; ++i) {
					for (int j = 0; j < 4; ++j) {
						QPoint temp(cube[2][b][v].faces[i][j].y, cube[2][b][v].faces[i][j].z);
						temp = transform.map(temp);
						cube[2][b][v].faces[i][j].y = temp.x();
						cube[2][b][v].faces[i][j].z = temp.y();
					}
				}
			}
		}
		transform.reset();
		repaint();
		if(slide<90)
		{
			cube = slidecube;
		}
		if(slide<46)
		{
			slide2-=1.555555;
		}
		else
		{
			slide2+=1.555555;
		}
	}
	auto temp = cube[2];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp[j][3 - 1 - i] = cube[2][i][j];
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cube[2][i][j] = temp[i][j];
		}
	}

	update();
}

void MainWindow::U()
{
	QVector<QVector<QVector<Cube>>> slidecube = cube;
	float slide2 = 0;
	for (int slide = 0 ; slide < 91; ++slide) {
		QTransform transform;
		if(slide<90)
		{
			transform.translate(slide*3.555,slide2);
		}
		else
		{
			transform.translate(slide*3.555,0);
		}
		transform.rotate(slide);
		for (int b = 0; b < 3; ++b) {
			for (int v = 0; v < 3; ++v) {
				for (int i = 0; i < 6; ++i) {
					for (int j = 0; j < 4; ++j) {
						QPoint temp(cube[b][0][v].faces[i][j].x, cube[b][0][v].faces[i][j].z);
						temp = transform.map(temp);
						cube[b][0][v].faces[i][j].x = temp.x();
						cube[b][0][v].faces[i][j].z = temp.y();
					}
				}
			}
		}
		transform.reset();
		repaint();
		if(slide<90)
		{
			cube = slidecube;
		}
		if(slide<46)
		{
			slide2-=1.555555;
		}
		else
		{
			slide2+=1.555555;
		}
	}
	QVector<QVector<Cube>> temp;
	temp.push_back(cube[0][0]);
	temp.push_back(cube[1][0]);
	temp.push_back(cube[2][0]);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp[3 - 1 - j][i] = cube[i][0][j];
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cube[i][0][j] = temp[i][j];
		}
	}
	update();
}

void MainWindow::U_()
{
	QVector<QVector<QVector<Cube>>> slidecube = cube;
	float slide2 = 0;
	for (int slide = 0 ; slide < 91; ++slide) {
		QTransform transform;
		if(slide<90)
		{
			transform.translate(slide2,slide*3.555);
		}
		else
		{
			transform.translate(0,slide*3.555);
		}
		transform.rotate(-slide);
		for (int b = 0; b < 3; ++b) {
			for (int v = 0; v < 3; ++v) {
				for (int i = 0; i < 6; ++i) {
					for (int j = 0; j < 4; ++j) {
						QPoint temp(cube[b][0][v].faces[i][j].x, cube[b][0][v].faces[i][j].z);
						temp = transform.map(temp);
						cube[b][0][v].faces[i][j].x = temp.x();
						cube[b][0][v].faces[i][j].z = temp.y();
					}
				}
			}
		}
		transform.reset();
		repaint();
		if(slide<90)
		{
			cube = slidecube;
		}
		if(slide<46)
		{
			slide2-=1.555555;
		}
		else
		{
			slide2+=1.555555;
		}
	}
	QVector<QVector<Cube>> temp;
	temp.push_back(cube[0][0]);
	temp.push_back(cube[1][0]);
	temp.push_back(cube[2][0]);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp[j][3 - 1 - i] = cube[i][0][j];
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cube[i][0][j] = temp[i][j];
		}
	}
	update();
}

void MainWindow::F()
{
	QVector<QVector<QVector<Cube>>> slidecube = cube;
	float slide2 = 0;
	for (int slide = 0 ; slide < 91; ++slide) {
		QTransform transform;
		if(slide<90)
		{
			transform.translate(slide*3.555,slide2);
		}
		else
		{
			transform.translate(slide*3.555,0);
		}
		transform.rotate(slide);
		for (int b = 0; b < 3; ++b) {
			for (int v = 0; v < 3; ++v) {
				for (int i = 0; i < 6; ++i) {
					for (int j = 0; j < 4; ++j) {
						QPoint temp(cube[b][v][0].faces[i][j].x, cube[b][v][0].faces[i][j].y);
						temp = transform.map(temp);
						cube[b][v][0].faces[i][j].x = temp.x();
						cube[b][v][0].faces[i][j].y = temp.y();
					}
				}
			}
		}
		transform.reset();
		repaint();
		if(slide<90)
		{
			cube = slidecube;
		}
		if(slide<46)
		{
			slide2-=1.555555;
		}
		else
		{
			slide2+=1.555555;
		}
	}
	QVector<QVector<Cube>> temp;
	temp.resize(3);
	for (int i = 0; i < 3; ++i) {
		temp[i].push_back(cube[0][i][0]);
		temp[i].push_back(cube[1][i][0]);
		temp[i].push_back(cube[2][i][0]);
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp[3 - 1 - j][i] = cube[i][j][0];
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cube[i][j][0] = temp[i][j];
		}
	}
	update();
}

void MainWindow::F_()
{
	QVector<QVector<QVector<Cube>>> slidecube = cube;
	float slide2 = 0;
	for (int slide = 0 ; slide < 91; ++slide) {
		QTransform transform;
		if(slide<90)
		{
			transform.translate(slide2,slide*3.555);
		}
		else
		{
			transform.translate(0,slide*3.555);
		}
		transform.rotate(-slide);
		for (int b = 0; b < 3; ++b) {
			for (int v = 0; v < 3; ++v) {
				for (int i = 0; i < 6; ++i) {
					for (int j = 0; j < 4; ++j) {
						QPoint temp(cube[b][v][0].faces[i][j].x, cube[b][v][0].faces[i][j].y);
						temp = transform.map(temp);
						cube[b][v][0].faces[i][j].x = temp.x();
						cube[b][v][0].faces[i][j].y = temp.y();
					}
				}
			}
		}
		transform.reset();
		repaint();
		if(slide<90)
		{
			cube = slidecube;
		}
		if(slide<46)
		{
			slide2-=1.555555;
		}
		else
		{
			slide2+=1.555555;
		}
	}
	QVector<QVector<Cube>> temp;
	temp.resize(3);
	for (int i = 0; i < 3; ++i) {
		temp[i].push_back(cube[0][i][0]);
		temp[i].push_back(cube[1][i][0]);
		temp[i].push_back(cube[2][i][0]);
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp[j][3 - 1 - i] = cube[i][j][0];
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cube[i][j][0] = temp[i][j];
		}
	}
	update();
}

void MainWindow::L()
{
	QVector<QVector<QVector<Cube>>> slidecube = cube;
	float slide2 = 0;
	for (int slide = 0 ; slide < 91; ++slide) {
		QTransform transform;
		if(slide<90)
		{
			transform.translate(slide*3.555,slide2);
		}
		else
		{
			transform.translate(slide*3.555,0);
		}
		transform.rotate(slide);
		for (int b = 0; b < 3; ++b) {
			for (int v = 0; v < 3; ++v) {
				for (int i = 0; i < 6; ++i) {
					for (int j = 0; j < 4; ++j) {
						QPoint temp(cube[0][b][v].faces[i][j].y, cube[0][b][v].faces[i][j].z);
						temp = transform.map(temp);
						cube[0][b][v].faces[i][j].y = temp.x();
						cube[0][b][v].faces[i][j].z = temp.y();
					}
				}
			}
		}
		transform.reset();
		repaint();
		if(slide<90)
		{
			cube = slidecube;
		}
		if(slide<46)
		{
			slide2-=1.555555;
		}
		else
		{
			slide2+=1.555555;
		}
	}
	auto temp = cube[0];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp[3 - 1 - j][i] = cube[0][i][j];
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cube[0][i][j] = temp[i][j];
		}
	}
	update();
}

void MainWindow::L_()
{
	QVector<QVector<QVector<Cube>>> slidecube = cube;
	float slide2 = 0;
	for (int slide = 0 ; slide < 91; ++slide) {
		QTransform transform;
		if(slide<90)
		{
			transform.translate(slide2,slide*3.555);
		}
		else
		{
			transform.translate(0,slide*3.555);
		}
		transform.rotate(-slide);
		for (int b = 0; b < 3; ++b) {
			for (int v = 0; v < 3; ++v) {
				for (int i = 0; i < 6; ++i) {
					for (int j = 0; j < 4; ++j) {
						QPoint temp(cube[0][b][v].faces[i][j].y, cube[0][b][v].faces[i][j].z);
						temp = transform.map(temp);
						cube[0][b][v].faces[i][j].y = temp.x();
						cube[0][b][v].faces[i][j].z = temp.y();
					}
				}
			}
		}
		transform.reset();
		repaint();
		if(slide<90)
		{
			cube = slidecube;
		}
		if(slide<46)
		{
			slide2-=1.555555;
		}
		else
		{
			slide2+=1.555555;
		}
	}
	auto temp = cube[0];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp[j][3 - 1 - i] = cube[0][i][j];
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cube[0][i][j] = temp[i][j];
		}
	}
	update();
}

void MainWindow::D()
{
	QVector<QVector<QVector<Cube>>> slidecube = cube;
	float slide2 = 0;
	for (int slide = 0 ; slide < 91; ++slide) {
		QTransform transform;
		if(slide<90)
		{
			transform.translate(slide*3.555,slide2);
		}
		else
		{
			transform.translate(slide*3.555,0);
		}
		transform.rotate(slide);
		for (int b = 0; b < 3; ++b) {
			for (int v = 0; v < 3; ++v) {
				for (int i = 0; i < 6; ++i) {
					for (int j = 0; j < 4; ++j) {
						QPoint temp(cube[b][2][v].faces[i][j].x, cube[b][2][v].faces[i][j].z);
						temp = transform.map(temp);
						cube[b][2][v].faces[i][j].x = temp.x();
						cube[b][2][v].faces[i][j].z = temp.y();
					}
				}
			}
		}
		transform.reset();
		repaint();
		if(slide<90)
		{
			cube = slidecube;
		}
		if(slide<46)
		{
			slide2-=1.555555;
		}
		else
		{
			slide2+=1.555555;
		}
	}
	QVector<QVector<Cube>> temp;
	temp.push_back(cube[0][2]);
	temp.push_back(cube[1][2]);
	temp.push_back(cube[2][2]);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp[3 - 1 - j][i] = cube[i][2][j];
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cube[i][2][j] = temp[i][j];
		}
	}
	update();
}

void MainWindow::D_()
{
	QVector<QVector<QVector<Cube>>> slidecube = cube;
	float slide2 = 0;
	for (int slide = 0 ; slide < 91; ++slide) {
		QTransform transform;
		if(slide<90)
		{
			transform.translate(slide2,slide*3.555);
		}
		else
		{
			transform.translate(0,slide*3.555);
		}
		transform.rotate(-slide);
		for (int b = 0; b < 3; ++b) {
			for (int v = 0; v < 3; ++v) {
				for (int i = 0; i < 6; ++i) {
					for (int j = 0; j < 4; ++j) {
						QPoint temp(cube[b][2][v].faces[i][j].x, cube[b][2][v].faces[i][j].z);
						temp = transform.map(temp);
						cube[b][2][v].faces[i][j].x = temp.x();
						cube[b][2][v].faces[i][j].z = temp.y();
					}
				}
			}
		}
		transform.reset();
		repaint();
		if(slide<90)
		{
			cube = slidecube;
		}
		if(slide<46)
		{
			slide2-=1.555555;
		}
		else
		{
			slide2+=1.555555;
		}
	}
	QVector<QVector<Cube>> temp;
	temp.push_back(cube[0][2]);
	temp.push_back(cube[1][2]);
	temp.push_back(cube[2][2]);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp[j][3 - 1 - i] = cube[i][2][j];
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cube[i][2][j] = temp[i][j];
		}
	}
	update();
}

void MainWindow::B()
{
	QVector<QVector<QVector<Cube>>> slidecube = cube;
	float slide2 = 0;
	for (int slide = 0 ; slide < 91; ++slide) {
		QTransform transform;
		if(slide<90)
		{
			transform.translate(slide*3.555,slide2);
		}
		else
		{
			transform.translate(slide*3.555,0);
		}
		transform.rotate(slide);
		for (int b = 0; b < 3; ++b) {
			for (int v = 0; v < 3; ++v) {
				for (int i = 0; i < 6; ++i) {
					for (int j = 0; j < 4; ++j) {
						QPoint temp(cube[b][v][2].faces[i][j].x, cube[b][v][2].faces[i][j].y);
						temp = transform.map(temp);
						cube[b][v][2].faces[i][j].x = temp.x();
						cube[b][v][2].faces[i][j].y = temp.y();
					}
				}
			}
		}
		transform.reset();
		repaint();
		if(slide<90)
		{
			cube = slidecube;
		}
		if(slide<46)
		{
			slide2-=1.555555;
		}
		else
		{
			slide2+=1.555555;
		}
	}
	QVector<QVector<Cube>> temp;
	temp.resize(3);
	for (int i = 0; i < 3; ++i) {
		temp[i].push_back(cube[0][i][2]);
		temp[i].push_back(cube[1][i][2]);
		temp[i].push_back(cube[2][i][2]);
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp[3 - 1 - j][i] = cube[i][j][2];
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cube[i][j][2] = temp[i][j];
		}
	}
	update();
}

void MainWindow::B_()
{
	QVector<QVector<QVector<Cube>>> slidecube = cube;
	float slide2 = 0;
	for (int slide = 0 ; slide < 91; ++slide) {
		QTransform transform;
		if(slide<90)
		{
			transform.translate(slide2,slide*3.555);
		}
		else
		{
			transform.translate(0,slide*3.555);
		}
		transform.rotate(-slide);
		for (int b = 0; b < 3; ++b) {
			for (int v = 0; v < 3; ++v) {
				for (int i = 0; i < 6; ++i) {
					for (int j = 0; j < 4; ++j) {
						QPoint temp(cube[b][v][2].faces[i][j].x, cube[b][v][2].faces[i][j].y);
						temp = transform.map(temp);
						cube[b][v][2].faces[i][j].x = temp.x();
						cube[b][v][2].faces[i][j].y = temp.y();
					}
				}
			}
		}
		transform.reset();
		repaint();
		if(slide<90)
		{
			cube = slidecube;
		}
		if(slide<46)
		{
			slide2-=1.555555;
		}
		else
		{
			slide2+=1.555555;
		}
	}
	QVector<QVector<Cube>> temp;
	temp.resize(3);
	for (int i = 0; i < 3; ++i) {
		temp[i].push_back(cube[0][i][2]);
		temp[i].push_back(cube[1][i][2]);
		temp[i].push_back(cube[2][i][2]);
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp[j][3 - 1 - i] = cube[i][j][2];
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cube[i][j][2] = temp[i][j];
		}
	}
	update();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
	QVector<QVector<QVector<Cube>>> temp = cube;
	QPainter painter(this);
	this->resize(1200,1200);
	painter.translate(450,450);
	for (int g = 0; g < 3; ++g) {
		for (int b = 0; b < 3; ++b) {
			for (int v = 0; v < 3; ++v) {
				QTransform transform;
				transform.rotate(ver);
				for (int i = 0; i < 6; ++i) {
					for (int j = 0; j < 4; ++j) {
						QPoint temp(cube[g][b][v].faces[i][j].x, cube[g][b][v].faces[i][j].y);
						temp = transform.map(temp);
						cube[g][b][v].faces[i][j].x = temp.x();
						cube[g][b][v].faces[i][j].y = temp.y();
					}
				}
				transform.reset();
				transform.rotate(hor);
				for (int i = 0; i < 6; ++i) {
					for (int j = 0; j < 4; ++j) {
						QPoint temp(cube[g][b][v].faces[i][j].x, cube[g][b][v].faces[i][j].z);
						temp = transform.map(temp);
						cube[g][b][v].faces[i][j].x = temp.x();
						cube[g][b][v].faces[i][j].z = temp.y();
					}
				}
				transform.reset();
			}
		}
	}
	//verC = horC = 0;
	QVector<Cube> mergedCube;
	for (const auto &plane : cube) {
		for (const auto &row : plane) {
			mergedCube.append(row);
		}
	}
	std::sort(mergedCube.begin(), mergedCube.end(), [](const Cube& a, const Cube& b) {
		float suma = 0;
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 4; ++j) {
				suma += a.faces[i][j].z;
			}
		}
		float sumb = 0;
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 4; ++j) {
				sumb += b.faces[i][j].z;
			}
		}
		return suma > sumb;
	});
	int index = 0;
	for (auto &plane : cube) {
		for (auto &row : plane) {
			for (Cube &c : row) {
				c = mergedCube[index++];
			}
		}
	}
	for (int g = 0; g < 3; ++g) {
		for (int b = 0; b < 3; ++b) {
			for (int v = 0; v < 3; ++v) {
				std::vector<std::pair<QVector<point3D>, QColor>> faceColorPairs;
				for (int i = 0; i < cube[g][b][v].faces.size(); ++i) {
					faceColorPairs.push_back(std::make_pair(cube[g][b][v].faces[i], cube[g][b][v].color[i]));
				}
				std::sort(faceColorPairs.begin(), faceColorPairs.end(), [](const std::pair<QVector<point3D>, QColor> &a, const std::pair<QVector<point3D>, QColor> &b) {
					float suma = a.first[0].z + a.first[1].z + a.first[2].z + a.first[3].z;
					float sumb = b.first[0].z + b.first[1].z + b.first[2].z + b.first[3].z;
					return (suma / 4) > (sumb / 4);
				});
				for (std::vector<std::pair<QVector<point3D>, QColor>>::size_type i = 0; i < faceColorPairs.size(); ++i) {
					cube[g][b][v].faces[i] = faceColorPairs[i].first;
					cube[g][b][v].color[i] = faceColorPairs[i].second;
				}
				//				QFont font = painter.font();
				//				font.setPointSize(font.pointSize() + 8);
				//				painter.setFont(font);
				for (int i = 3; i < 6; ++i) {
					QBrush brush(cube[g][b][v].color[i]);
					QPolygon polygon;
					int totalX = 0.0;
					int totalY = 0.0;
					for (int j = 0; j < 4; ++j) {
						polygon << QPoint(cube[g][b][v].faces[i][j].x, cube[g][b][v].faces[i][j].y);
						totalX += cube[g][b][v].faces[i][j].x;
						totalY += cube[g][b][v].faces[i][j].y;
					}
					painter.setBrush(brush);
					painter.drawPolygon(polygon);
					//		QString text;
					//		if (cube[g][b][v].p[i].second == QColor(255, 140, 0)) {
					//			text = "1";
					//		}else if (cube[g][b][v].p[i].second == QColor(255,0,0)) {
					//			text = "2";
					//		}else if (cube[g][b][v].p[i].second == QColor(0,255,0)) {
					//			text = "3";
					//		}else if (cube[g][b][v].p[i].second == QColor(255,255,255)) {
					//			text = "4";
					//		}else if (cube[g][b][v].p[i].second == QColor(255,255,0)) {
					//			text = "5";
					//		}else if (cube[g][b][v].p[i].second == QColor(0,0,255)) {
					//			text = "6";
					//		}
					//		painter.drawText(totalX/4-5, totalY/4+10, text);
				}
			}
		}
	}
	cube = temp;
	//ver--;
	//hor--;
	update();
}
