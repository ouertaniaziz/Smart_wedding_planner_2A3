#ifndef ARDUINO_H
#define ARDUINO_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>


class arduino_yassine
{
public:
    arduino_yassine();
    int connect_arduino_yassine_sami(); // pour se connecter a l'arduino
    int close_arduino_yassine_sami(); // pour couper la connection a l'arduino
    int write_to_arduino_yassine_sami(QByteArray); // envoyer info a arduino
    QByteArray read_from_arduino_yassine_sami(); // reçoi info de l'arduino

    //accesseurs

    QSerialPort* getserial_yassine_sami();
    QString getarduino_port_name_yassine_sami();

private:
    QSerialPort* serial; // variable pour envoyer ou recevoire donnée entre pc et arduino
    static const quint16 arduino_uno_vendor_id=9025; // des constantes de 16 bytes
    static const quint16 arduino_uno_product_id=67; // des constantes de 16 bytes
    QString arduino_port_name;  // pour prender le nom du port l'arduino se conenct au pc
    bool arduino_is_available; // verifie la conenction entre arduino et pc

    QByteArray data;  // pour recevoire et envoyer les données

};

#endif // ARDUINO_H
