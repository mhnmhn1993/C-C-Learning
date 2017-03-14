#include <config.h>
#include <iostream>
#include <fstream>

config::config(int port,std::string ip,std::string IPmode,std::string protocol,std::string processing,std::string version){
    this->IP=ip;
    this->port=port;
    this->protocol=protocol;
    this->processing=processing;
    this->version=version;
    this->IPmode=IPmode;
}
config::config(std::string filename){
    this->filename=filename;
}

bool config::isOneOf(const std::vector<std::string> &vec, std::string name)
{

    for(int i=0;i<vec.size();i++){
        if(vec[i]==name) return true;
        else continue;
    }
    return false;
}

void config::read()
{
    std::ifstream in(filename);
    if (!in.is_open()){
        std::cout << "Error opening file";
        return;
    }
    for(int i=1;!in.eof();i++){
        std::string line;
        getline(in,line);
        analyze(line,i);
    }
    if(protocol_flag==0){
        std::cout<<"protocol information is missing"<<std::endl;
    }
    if(IPmode_flag==0){
        std::cout<<"IPmode information is missing"<<std::endl;
    }
    if(port_flag==0){
        std::cout<<"port information is missing"<<std::endl;
    }
    if(processing_flag==0){
        std::cout<<"processing information is missing"<<std::endl;
    }
    if(version_flag==0){
        std::cout<<"version information is missing"<<std::endl;
    }
    if(IP_flag==0){
        std::cout<<"IP information is missing"<<std::endl;
    }


}

std::string config::getIPAddress()
{
    if(IP_flag==1){
        return this->IP;
    }
    else{
        std::cout<<"IP information is missing"<<std::endl;
        return "";
    }
}

std::string config::getProtocol()
{
    if(protocol_flag==1){
        return this->protocol;
    }
    else{
        std::cout<<"protocol information is missing"<<std::endl;
        return "";
    }
}

std::string config::getProcessing()
{
    if(processing_flag==1){
        return this->processing;
    }
    else{
        std::cout<<"processing information is missing"<<std::endl;
        return "";
    }
}

std::string config::getVersion()
{
    if(version_flag==1){
        return this->version;
    }
    else{
        std::cout<<"version information is missing"<<std::endl;
        return "";
    }
}

std::string config::getIPmode()
{
    if(IPmode_flag==1){
        return this->IPmode;
    }
    else{
        std::cout<<"IPmode information is missing"<<std::endl;
        return "";
    }
}

int config::getPort()
{
    if(port_flag==1){
        return this->port;
    }
    else{
        std::cout<<"port information is missing"<<std::endl;
        return -1;
    }
}

void config::write()
{
    this->write("config.cfg");
}

void config::write(const std::string &filename)
{
    this->filename=filename;

    if(test()){
        std::ofstream out(filename);
        if (!out.is_open()){
            std::cout << "Error opening file";
            return;
        }


        out<<"PROTOCOL:"<<this->protocol<<std::endl;
        out<<"IPmode:"<<this->IPmode<<std::endl;
        out<<"PORT:"<<this->port<<std::endl;
        out<<"PROCESSING:"<<this->processing<<std::endl;
        out<<"VERSION:"<<this->version<<std::endl;
        out<<"IP:"<<this->IP<<std::endl;
        std::cout<<"write completed"<<std::endl;
    }
    else {
        std::cout<<"information incompleted"<<std::endl;
    }
}

bool config::test()
{
    if(protocol_flag==0 && protocol!=""){
        if(isOneOf(PROTOCOLS,protocol)){
            protocol_flag=1;
        }
        else{
            std::cout<<" protocol should be one of the ";
            for(int i=0;i<PROTOCOLS.size();i++){
            std::cout<<PROTOCOLS[i]<<" ";
            }
            std::cout<<std::endl;
        }
    }

    if(IPmode_flag==0 && IPmode!=""){
        if(isOneOf(IPMODE,IPmode)){
            IPmode_flag=1;
        }
        else{
            std::cout<<" IPmode should be one of the ";
            for(int i=0;i<IPMODE.size();i++){
            std::cout<<IPMODE[i]<<" ";
            }
            std::cout<<std::endl;
        }
    }

    if(port_flag==0 && port!=-1){
        port_flag=1;
    }

    if(processing_flag==0 && processing!=""){
        if(isOneOf(PROCESSING,processing)){
            processing_flag=1;
        }
        else{
            std::cout<<" processing should be one of the ";
            for(int i=0;i<PROCESSING.size();i++){
            std::cout<<PROCESSING[i]<<" ";
            }
            std::cout<<std::endl;
        }
    }

    if(IP_flag==0 && IP!=""){
        int count=0;
        for(int i=0;IP[i]!='\0';i++){
            if(IP[i]<='9' && IP[i]>='0') continue;
            else if(IP[i]='.'){
                count++;
                continue;
            }
            else{
                std::cout<<"IP format is wrong"<<std::endl;
            }
        }
        if(count==3){
            IP_flag=1;
        }
        else{
            std::cout<<"IP format is wrong"<<std::endl;
        }
    }

    if(version_flag==0 && version!=""){
        int count=0;
        for(int i=0;version[i]!='\0';i++){
            if(version[i]<='9' && version[i]>='0') continue;
            else if(version[i]='.'){
                count++;
                continue;
            }
            else{
                std::cout<<"version format is wrong"<<std::endl;
            }
        }
        if(count==2){
            version_flag=1;
        }
        else{
            std::cout<<"version format is wrong"<<std::endl;
        }
    }

    /*std::cout<<protocol_flag<<std::endl;
    std::cout<<IPmode_flag<<std::endl;
    std::cout<<port_flag<<std::endl;
    std::cout<<processing_flag<<std::endl;
    std::cout<<version_flag<<std::endl;
    std::cout<<IP_flag<<std::endl;*/

    if(IP_flag&&protocol_flag&&IPmode_flag&&version_flag&&port_flag&&processing_flag == 1){
        return true;
    }
    else return false;
}


void config::analyze(std::string line,int c)
{
    int name_flag=0;
    std::string content="";
    std::string name="";
    for(int i=0;line[i]!='\0';i++){
        if(line[i]=='#'){
            std::cout<<"line "<<c<<": is comments"<<std::endl;;
            return;
        }

        if(name_flag==0 && line[i]!=':'){
            name+=line[i];
            continue;
        }
        if(name_flag==0 && line[i]==':'){
            //name+='\0';
            name_flag=1;
            continue;
        }
        if(name_flag==1 && line[i]!=' '){
            content+=line[i];
            continue;
        }
    }

    if(name=="PROTOCOL"){
        if(protocol_flag==1){
            std::cout<<"line "<<c<<": repeatedly define protocol information.will use the first information."<<std::endl;
            return;
        }
        else if(isOneOf(PROTOCOLS,content)){
            this->protocol=content;
            std::cout<<"line "<<c<<": protocol = "<<content<<std::endl;
            protocol_flag=1;
            return;
        }
        else{
            std::cout<<"line "<<c<<": protocol should be one of the ";
            for(int i=0;i<PROTOCOLS.size();i++){
                std::cout<<PROTOCOLS[i]<<" ";
            }
            std::cout<<std::endl;
            return;
        }
    }
    else if(name=="IPmode"){
        if(IPmode_flag==1){
            std::cout<<"line "<<c<<": repeatedly define IPmode information.will use the first information."<<std::endl;
            return;
        }
        else if(isOneOf(IPMODE,content)){
            this->IPmode=content;
            std::cout<<"line "<<c<<": IPmode = "<<content<<std::endl;
            IPmode_flag=1;
            return;
        }
        else{
            std::cout<<"line "<<c<<": IPmode should be one of the ";
            for(int i=0;i<IPMODE.size();i++){
                std::cout<<IPMODE[i]<<" ";
            }
            std::cout<<std::endl;
            return;
        }
    }

    else if(name=="PORT"){
        if(port_flag==1){
            std::cout<<"line "<<c<<": repeatedly define port information.will use the first information."<<std::endl;
            return;
        }
        else{
            for(int i=0;content[i]!='\0';i++){
                if(content[i]<='9' && content[i]>='0') continue;
                else{
                    std::cout<<"line "<<c<<": format wrong, type of the port should be an integer"<<std::endl;
                    return;
                }
            }
            this->port=atoi(content.c_str());
            port_flag=1;
            std::cout<<"line "<<c<<": port = "<<content<<std::endl;
            return;
        }
    }

    else if(name=="PROCESSING"){
        if(processing_flag==1){
            std::cout<<"line "<<c<<": repeatedly define processing information.will use the first information."<<std::endl;
            return;
        }
        else if(isOneOf(PROCESSING,content)){
            this->IPmode=content;
            std::cout<<"line "<<c<<": processing = "<<content<<std::endl;
            processing_flag=1;
            return;
        }
        else{
            std::cout<<"line "<<c<<": processing should be one of the ";
            for(int i=0;i<PROCESSING.size();i++){
                std::cout<<PROCESSING[i]<<" ";
            }
            std::cout<<std::endl;
            return;
        }
    }

    else if(name=="VERSION"){
        if(version_flag==1){
            std::cout<<"line "<<c<<": repeatedly define version information.will use the first information."<<std::endl;
            return;
        }
        else{
            int count=0;
            for(int i=0;content[i]!='\0';i++){
                if(content[i]<='9' && content[i]>='0') continue;
                else if(content[i]='.'){
                    count++;
                    continue;
                }
                else{
                    std::cout<<"line "<<c<<": format wrong, type of the version should be like 'X.X.X'"<<std::endl;
                    return;
                }
            };
            if(count<2){
                std::cout<<"line "<<c<<": format wrong, type of the version should be like 'X.X.X'"<<std::endl;
                return;
            }

            this->version=content;
            version_flag=1;
            std::cout<<"line "<<c<<": version = "<<content<<std::endl;
            return;
        }
    }

    else if(name=="IP"){
        if(IP_flag==1){
            std::cout<<"line "<<c<<": repeatedly define IP information.will use the first information."<<std::endl;
            return;
        }
        else{
            int count=0;
            for(int i=0;content[i]!='\0';i++){
                if(content[i]<='9' && content[i]>='0') continue;
                else if(content[i]=='.'){
                    count++;
                    continue;
                }
                else  {
                    std::cout<<"line "<<c<<": format wrong, type of the IP should be like 'XXX.XXX.XXX.XXX'"<<std::endl;
                    return;
                }
            }
            if(count<3){
                std::cout<<"line "<<c<<": format wrong, type of the IP should be like 'XXX.XXX.XXX.XXX'"<<std::endl;
                return;
            }

            this->IP=content;
            IP_flag=1;
            std::cout<<"line "<<c<<": IP = "<<content<<std::endl;
            return;
        }
    }
    else{
        std::cout<<"line "<<c<<": connot be recognized"<<std::endl;
        return;
    };
}