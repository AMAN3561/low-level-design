#include<iostream>
#include<string>
using namespace std;

/// 1: Target interface expected by the client :
class IReports{
public:  
    virtual string getjsonData(const string& data) = 0;
    virtual ~IReports(){}
};

// 2 : Adapter: provides XML data from a raw input :
class XmlDataProvider{
public:
    // expect data in "name: id" format (e.g. "Alice:42")
    string getXmlData(const string& data){
    size_t sep = data.find(':');
    string name = data.substr(0, sep);
    string id = data.substr(sep + 1);
    // build an XML representation:
    return  "<user>"
            "<name>" + name + "</name>"
            "<id>" + id + "</id>"
            "</user";
    }
};

class XmlDataProviderAdaper : public IReports{
private:
    XmlDataProvider* xmlProvider;
public:
    XmlDataProviderAdaper(XmlDataProvider* provider){
        this->xmlProvider = provider;
    }
    string getjsonData(const string& data) override {
        // 1: get XML from the adapter :
        string xml = xmlProvider->getXmlData(data);

        // 2 : naively parse out <name> and <id> values :
        size_t startname = xml.find("<name>") + 6;
        size_t endname = xml.find("</name>");
        string name = xml.substr(startname, endname - startname);

        size_t startid = xml.find("<id>") + 4;
        size_t endid = xml.find("</id>");
        string id = xml.substr(startid, endid - startid);

        // build and return json :
        return "{\"name\":\"" + name + "\", \"id\":" + id + "}";
    }

};

class Client{
public:
    void getReport(IReports* report, string rawdata){
        cout << "Processed JSON :"
             << report->getjsonData(rawdata)
             << endl;
    }
};

int main(){
    // 1 : create the adapter :
    XmlDataProvider* xmlProv = new  XmlDataProvider();

    // 2 : make our adapter :
    IReports* adapter = new XmlDataProviderAdaper(xmlProv);

    // give it some raw data :
    string rawdata = "Alice:42";

    // client prints the json:

    Client* client = new Client();
    client->getReport(adapter, rawdata);

    // processed JSON : {"name": "Alice", "id" : "42"}

    // cleanup 
    delete adapter;
    delete xmlProv;
    return 0;
}