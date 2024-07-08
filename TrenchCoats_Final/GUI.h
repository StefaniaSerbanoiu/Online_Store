#pragma once
#include <qwidget.h>
#include "Service.h"

#include <qpushbutton.h>
#include <qlistwidget.h>
#include <qlineedit.h>

#include <QBoxLayout.h>
#include <qformlayout.h>
#include <qmessagebox.h>
#include <sstream>

#include <qgridlayout.h>
#include <qobject.h>




class GUI : public QWidget
{

private:
	Service& serv;

	QListWidget* list_widget;

	QLineEdit* link_line_edit;
	QLineEdit* size_line_edit;
	QLineEdit* color_line_edit;
	QLineEdit* price_line_edit;
	QLineEdit* quantity_line_edit;

	QPushButton* add_button, * delete_button, * update_button;

	void init_GUI();
	void populate_list();
	void init_fields();

	int get_current_index();

	void connect();

	void add_functionality();
	void delete_functionality();
	void update_functionality();


public:
	GUI(Service& service);
	~GUI() {}
};