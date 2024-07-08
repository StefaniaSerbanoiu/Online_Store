#include "GUI.h"



// GUI constructor
GUI::GUI(Service& service) : serv(service)
{
	init_GUI();
	populate_list();
	connect();
	
}


void GUI::init_GUI()
{
	this->list_widget = new QListWidget();

	this->link_line_edit = new QLineEdit();
	this->color_line_edit = new QLineEdit();
	this->size_line_edit = new QLineEdit();
	this->price_line_edit = new QLineEdit();
	this->quantity_line_edit = new QLineEdit();

	this->add_button = new QPushButton("Add");
	this->delete_button = new QPushButton("Delete");
	this->update_button = new QPushButton("Update");

	QVBoxLayout* main_layout = new QVBoxLayout(this);
	main_layout->addWidget(this->list_widget);

	QFormLayout* form_layout = new QFormLayout();
	form_layout->addRow("Photograph: ", this->link_line_edit);
	form_layout->addRow("Size: ", this->size_line_edit);
	form_layout->addRow("Color: ", this->color_line_edit);
	form_layout->addRow("Price: ", this->price_line_edit);
	form_layout->addRow("Quantity: ", this->quantity_line_edit);

	main_layout->addLayout(form_layout);

	QGridLayout* buttons_layout = new QGridLayout();
	buttons_layout->addWidget(this->add_button, 0, 0);
	buttons_layout->addWidget(this->delete_button, 0, 1);
	buttons_layout->addWidget(this->update_button, 0, 2);
	main_layout->addLayout(buttons_layout);

}


void GUI::populate_list()
{
	auto products = this->serv.getRepo()->getAllObjectsFromRepository();
	int length = products.size();

	list_widget->clear(); // make it empty

	int i = 21;
	int index = 0;
	

	for (; index < length; index++)
	{
		list_widget->addItem(QString::fromStdString(products[index].getPhotograph()));
	}
}


void GUI::connect()
{
	QObject::connect(list_widget, &QListWidget::clicked, this, &GUI::init_fields);

	QObject::connect(
		add_button,
		&QPushButton::clicked,
		this,
		&GUI::add_functionality
	);

	QObject::connect(
		delete_button,
		&QPushButton::clicked,
		this,
		&GUI::delete_functionality
	);

	QObject::connect(
		update_button,
		&QPushButton::clicked,
		this,
		&GUI::update_functionality
	);
}



int GUI::get_current_index()
{
	auto indexes = list_widget->selectionModel()->currentIndex();
	return indexes.row();
}


void GUI::init_fields()
{
	int index = get_current_index();
	auto products = serv.getRepo()->getObjectOnPosition(index);
	link_line_edit->setText(QString::fromStdString(products.getPhotograph()));
	color_line_edit->setText(QString::fromStdString(products.getColor()));
	size_line_edit->setText(QString::fromStdString(to_string(products.getSize())));
	price_line_edit->setText(QString::fromStdString(to_string(products.getPrice())));
	quantity_line_edit->setText(QString::fromStdString(to_string(products.getQuantity())));
}




void GUI::add_functionality()
{
	auto link = this->link_line_edit->text().toStdString();
	auto color = this->color_line_edit->text().toStdString();
	auto size = stoi(this->size_line_edit->text().toStdString());
	auto price = stoi(this->price_line_edit->text().toStdString());
	auto quantity = stoi(this->quantity_line_edit->text().toStdString());

	// now add the new product
	this->serv.addService(Product(size, color, price, quantity, link));

	// make the change visible
	this->populate_list();
}


void GUI::delete_functionality()
{
	auto link = this->link_line_edit->text().toStdString();

	// remove the product from the repository by using the service function
	this->serv.removeService(link);

	// make the change visible
	this->populate_list();
}


void GUI::update_functionality()
{
	// get the new data
	auto link = this->link_line_edit->text().toStdString();
	auto color = this->color_line_edit->text().toStdString();
	auto size = stoi(this->size_line_edit->text().toStdString());
	auto price = stoi(this->price_line_edit->text().toStdString());
	auto quantity = stoi(this->quantity_line_edit->text().toStdString());

	// make the update in the repo by using the service function
	this->serv.updateService(link, size, color, price, quantity);

	// make the change visible
	this->populate_list();
}

