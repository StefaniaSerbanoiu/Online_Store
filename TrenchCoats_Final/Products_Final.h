#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Products_Final.h"

class Products_Final : public QMainWindow
{
    Q_OBJECT

public:
    Products_Final(QWidget *parent = nullptr);
    ~Products_Final();

private:
    Ui::Product_FinalClass ui; // originally the app stored just trench coats
};
