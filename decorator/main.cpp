#include <iostream>
#include "Types.h"

int main() {
    DataSource* dataSource = new FileDataSource("test.txt");
    DataSource* output = new FileDataSource("output.txt");
    std::string data = dataSource->readData();
    std::cout<<data<<"\n";
    DataSource* enc = new EncryptionDecorator(*output, "test");
    DataSource* enc2 =  new EncryptionDecorator(*enc, "tset");
    DataSource* enc3 =  new EncryptionDecorator(*enc2, "Ala ma kota");
    DataSource* encWriter = new DataSourceDecorator(*enc3);
    encWriter->writeData(data);
    std::string decrypted_data = encWriter->readData();
    std::cout<<decrypted_data<<"\n";
    delete dataSource;
    delete output;
    delete encWriter;
    delete enc;
    delete enc2;
    delete enc3;
    return 0;
}
