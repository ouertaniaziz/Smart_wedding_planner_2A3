#include "arduino_yassine.h"
#include <QDebug>

arduino_yassine::arduino_yassine()
{
    data="";
    arduino_port_name="";
    arduino_is_available= false;
    serial=new QSerialPort;
}

//les accesseurs


QString arduino_yassine::getarduino_port_name_yassine_sami()
{return arduino_port_name;}

QSerialPort* arduino_yassine::getserial_yassine_sami()
{return serial;}





int arduino_yassine::connect_arduino_yassine_sami()
{
    foreach(const QSerialPortInfo& serial_port_info,QSerialPortInfo::availablePorts())
    {
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
        {
            if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier() == arduino_uno_product_id)
            {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();

            }
        }
    }
    qDebug() << "arduino port name" <<arduino_port_name ;

    if (arduino_is_available)
    {
        serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite))
        {
            serial->open(QSerialPort::ReadOnly);
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            return 0;
        }
        return 1;
    }
    return -1;
}

int arduino_yassine::close_arduino_yassine_sami()
{
    if(serial->isOpen())
    {
        serial->close();
        return 0;
    }
    return 1;
}


int arduino_yassine::write_to_arduino_yassine_sami(QByteArray d)
{
    if (serial->isWritable())
    {
        serial->write(d);
    }
    else
        qDebug() << "erreur en ecriture";
}



QByteArray arduino_yassine::read_from_arduino_yassine_sami()
{
    if(serial->isReadable())
    {
        data = serial->readAll();
        return data;
    }
}













