#include "Message.h"

Message::Message(std::string Messagedata)
{
    this->contentLength = Messagedata.length();
    this->Encoding = "";
    this->data = Messagedata;
    this->Origin = "";
    this->Destination = "";
}

Message::Message(Message *msg)
{
    this->data = msg->data;
}

std::string Message::getData()
{
    return this->data;
}

std::string Message::getDestination()
{
    if(this->Destination == "" || this->getDestinationPort() == "ERROR: PORT NOT SET" || this->getDestinationIP() == "ERROR: IPV4 NOT SET")
        return "ERROR: INCOMPLETE ADDRESS";
    else
        return this->Destination;
}

std::string Message::getOrigin()
{
    if(this->Origin == "" || this->getOriginPort() == "ERROR: PORT NOT SET" || this->getOriginIP() == "ERROR: IPV4 NOT SET")
        return "ERROR: INCOMPLETE ADDRESS";
    else
        return this->Origin;
}

std::string Message::getEncoding()
{
    return this->Encoding;
}

std::string Message::getDestinationIP()
{
    std::string IP = this->Destination;
    int pos = IP.find(':');

    if(pos == std::string::npos)
        return "ERROR: IPV4 NOT SET";

    IP = IP.substr(0, pos);

    if(IP == "")
        return "ERROR: IPV4 NOT SET";

    return IP;
}

std::string Message::getDestinationPort()
{
    std::string port = this->Destination;
    int pos = port.find(':');

    if(pos == std::string::npos)
    {
        port = this->Destination;
        if (port == "")
            return "ERROR: PORT NOT SET";
        else
        {
            return port;
        }
    }
    else
    {
        port = port.substr(pos+1);
        if (port == "")
            return "ERROR: PORT NOT SET";
        else
        {
            return port;
        }
    }
}

std::string Message::getOriginIP()
{
    std::string IP;
    int pos = Origin.find(':');

    if(pos == std::string::npos)
        return "ERROR: IPV4 NOT SET";

    IP = Origin.substr(0, pos);

    if(IP.empty()){
        return "ERROR: IPV4 NOT SET";
    }

    return IP;
}

std::string Message::getOriginPort()
{
    std::string port = this->Origin;
    int pos = 0;
    pos = port.find(':');

    if(pos == std::string::npos)
    {
        port = this->Origin;
        if (port == "")
            return "ERROR: PORT NOT SET";
        else
        {
            return port;
        }
    }
    else
    {
        port = port.substr(pos+1);
        if (port == "")
            return "ERROR: PORT NOT SET";
        else
        {
            return port;
        }
    }
}

bool Message::setDestinationIP(std::string DestIP)
{
    if(getDestinationIP() != "ERROR: IPV4 NOT SET")
        return false;

    std::string address[4];
    int numMaxInclusive = 255, numMinInclusive = 0;

    int numDots = 0;
    for (int i = 0; i < DestIP.length(); ++i)
    {
        if (DestIP[i] == '.')
        {
            numDots++;
        }
    }

    if (numDots != 3)
    {
        return false;
    }

    std::string copy = DestIP;
    for (int i = 0; i < 3; ++i) {
        int pos = copy.find('.');
        address[i] = copy.substr(0, pos);
        copy.erase(0, pos+1);
    }
    address[3] = copy;

    std::string IP;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < address[i].length(); ++j)
        {

            if(!std::isdigit(address[i][j]))
            {
                return false;
            }
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        int temp;
        std::stringstream ss(address[i]);
        ss >> temp;
        if(temp > numMaxInclusive || temp < numMinInclusive)
        {
            return false;
        }
    }

    this->Destination = DestIP + ":" + Destination;
    return true;
}

bool Message::setDestinationPort(std::string DestPort)
{
    if(getDestinationPort() != "ERROR: PORT NOT SET")
        return false;

    int numMaxInclusive = 65535, numMinInclusive = 0;

    std::string Port = DestPort;
    for (int j = 0; j < Port.length(); ++j)
    {
        if(!std::isdigit(Port[j]))
        {
            return false;
        }
    }

    int temp;
    std::stringstream ss(Port);
    ss >> temp;
    if(temp > numMaxInclusive || temp < numMinInclusive)
    {
        return false;
    }

    this->Destination = Destination + DestPort;
    return true;
}

bool Message::setOriginIP(std::string OriginIP)
{
    if(getOriginIP() != "ERROR: IPV4 NOT SET")
        return false;

    std::string address[4];
    int numMaxInclusive = 255, numMinInclusive = 0;

    int numDots = 0;
    for (int i = 0; i < OriginIP.length(); ++i)
    {
        if (OriginIP[i] == '.')
        {
            numDots++;
        }
    }

    if (numDots != 3)
    {
        return false;
    }

    std::string copy = OriginIP;
    for (int i = 0; i < 3; ++i) {
        int pos = copy.find('.');
        address[i] = copy.substr(0, pos);
        copy.erase(0, pos+1);
    }
    address[3] = copy;

    std::string IP;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < address[i].length(); ++j)
        {

            if(!std::isdigit(address[i][j]))
            {
                return false;
            }
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        int temp;
        std::stringstream ss(address[i]);
        ss >> temp;
        if(temp > numMaxInclusive || temp < numMinInclusive)
        {
            return false;
        }
    }

    this->Origin = OriginIP + ":" + Origin;
    return true;
}

bool Message::setOriginPort(std::string OriginPort)
{
    if(getDestinationPort() != "ERROR: PORT NOT SET")
        return false;

    int numMaxInclusive = 65535, numMinInclusive = 0;

    std::string Port = OriginPort;
    for (int j = 0; j < Port.length(); ++j)
    {
        if(!std::isdigit(Port[j]))
        {
            return false;
        }
    }

    int temp;
    std::stringstream ss(Port);
    ss >> temp;
    if(temp > numMaxInclusive || temp < numMinInclusive)
    {
        return false;
    }

    this->Origin = Origin + OriginPort;
    return true;
}

void Message::setEncoding(std::string Encoding)
{
    this->Encoding = Encoding;
}

void Message::PrintMessage()
{
    std::cout << "Data: " << this->getData() << std::endl;
    std::cout << "Destination: " << this->getDestination() << std::endl;
    std::cout << "Destination IPV4: " << this->getDestinationIP() << std::endl;
    std::cout << "Destination Port: " << this->getDestinationPort() << std::endl;
    std::cout << "Origin: " << this->getOrigin() << std::endl;
    std::cout << "Origin IPV4: " << this->getOriginIP() << std::endl;
    std::cout << "Origin Port: " << this->getOriginPort() << std::endl;
    std::cout << "Encoding: " << this->getEncoding() << std::endl;
}

Message::~Message()
{
    std::cout << "Deleted message containing: " << this->data << std::endl;
}

int Message::getContentLength()
{
    return this->contentLength;
}

void Message::setContentLength(int contentLength)
{
    this->contentLength = contentLength;
}
