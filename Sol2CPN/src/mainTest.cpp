#include <fstream>
#include <iostream>
#include <sstream>

#include "include/Helena.hpp"

int main1(int argc, char** argv){

//ContractDefinitionNodePtr contract(new ContractDefinitionNode(contract_name));

    SOL2CPN::NetNodePtr nn(new SOL2CPN::NetNode());
    nn->set_name("n1");
    SOL2CPN::ParameterNodePtr pn1(new SOL2CPN::ParameterNode()), pn2(new SOL2CPN::ParameterNode());
    pn1->set_name("pn1");
    pn2->set_name("pn2");
    pn1->set_number("1");
    pn2->set_number("2");
    nn->add_parameter(pn1);
    nn->add_parameter(pn2);
    SOL2CPN::ColorNodePtr cn1(new SOL2CPN::ColorNode()), cn2(new SOL2CPN::ColorNode());
    cn1->set_name("c1");
    cn1->set_typeDef("def1");
    cn2->set_name("c2");
    cn2->set_typeDef("def2");
    
    nn->add_member(cn1);
    nn->add_member(cn2);

    SOL2CPN::FunctionNodePtr f1(new SOL2CPN::FunctionNode());
    f1->set_name("f1");
    f1->set_returnType("r1");
    SOL2CPN::ParamNodePtr p1(new SOL2CPN::ParamNode());
    p1->set_name("p1");
    p1->set_type("t1");
    SOL2CPN::ParamNodePtr p2(new SOL2CPN::ParamNode());
    p2->set_name("p2");
    p2->set_type("t2");
    f1->add_parameter(p1);
    f1->add_parameter(p2);

    nn->add_member(f1);
    
    SOL2CPN::PlaceNodePtr pl1(new SOL2CPN::PlaceNode());
    pl1->set_name("pl1");
    pl1->set_domain(cn1->get_name());
    SOL2CPN::ArcNodePtr i1(new SOL2CPN::ArcNode());
    i1->set_placeName(pl1->get_name());
    i1->set_label("<(x)>");
    SOL2CPN::ArcNodePtr i2(new SOL2CPN::ArcNode());
    i2->set_placeName(pl1->get_name());
    i2->set_label("<(y)>");
    SOL2CPN::TransitionNodePtr tr1(new SOL2CPN::TransitionNode());
    tr1->set_name("tr1");
    tr1->add_inArc(i1);
    tr1->add_outArc(i2);
    nn->add_member(tr1);

    std::string new_source = nn->source_code();
    std::ofstream output_file_stream("/home/ikramz/Desktop/test1.lna");
    output_file_stream << new_source;
    output_file_stream.close();
    
    return 0;
}