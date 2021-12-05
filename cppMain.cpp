#include "rapidjson/document.h"
#include "rapidjson/error/en.h"
#include <iostream>s

static const char* sample_json = R"(
{
    "pets": "dog",
    "age": 5,
    "like": [
        "walking",
        "eating",
        "hamster"
    ]
}
)";

int main(){
    rapidjson::Document doc;
    doc.Parse(sample_json);
    if(doc.HasParseError()) {
        std::cout << "error offset:" << doc.GetErrorOffset() << std::endl;
        std::cout << "error pase:" << rapidjson::GetParseError_En(doc.GetParseError()) << std::endl;
        return 1;        
    }

    std::cout << "---- string ----" << std::endl;
    if(!doc["pets"].IsString()) {
        std::cout << "pets value is not string" << std::endl;
        return 1;
    }
    const char* a = doc["pets"].GetString();
    std::cout << "pets value:" << a << std::endl;

    std::cout << "---- list ----" << std::endl;
    const rapidjson::Value& c = doc["like"].GetArray();

    for (auto& d : c.GetArray()) {
        const char* e = d.GetString();
        std::cout << "list value:" << e << std::endl;
    }

    std::cout << "---- key list ----" << std::endl;
    for(rapidjson::Value::ConstMemberIterator itr = doc.MemberBegin(); itr != doc.MemberEnd(); ++itr) {
            std::cout << "key name:" << itr->name.GetString() << std::endl;
    }

    return 0;
}