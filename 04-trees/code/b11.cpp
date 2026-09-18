// B11 哈夫曼树构建、编码与解码
#include "../../templates/test_support.hpp"

struct HuffNode { long long weight=0; int left=-1; int right=-1; int symbol=-1; };
struct HuffTree { std::vector<HuffNode> nodes; int root=-1; };
HuffTree build_huffman(const std::vector<long long>& weights) {
    (void)weights;
    todo("build_huffman");
}
std::vector<std::string> make_codes(const HuffTree& tree, int symbol_count) {
    (void)tree;
    (void)symbol_count;
    todo("make_codes");
}
std::vector<int> decode_bits(const HuffTree& tree, const std::string& bits) {
    (void)tree;
    (void)bits;
    todo("decode_bits");
}

void check_huffman(const std::vector<long long>& weights, long long expected_wpl) {
    auto tree=build_huffman(weights);
    if(weights.empty()) {
        practice_test::require(tree.root==-1 && tree.nodes.empty(),"empty huffman");
        practice_test::require(make_codes(tree,0).empty() && decode_bits(tree,"").empty(),"empty codes");
        return;
    }
    practice_test::equal(tree.nodes.size(),2*weights.size()-1,"full binary tree size");
    std::unordered_set<int> seen;
    std::vector<int> symbols(weights.size(),0);
    std::function<long long(int)> validate=[&](int index)->long long {
        practice_test::require(index>=0 && static_cast<std::size_t>(index)<tree.nodes.size(),"node index");
        practice_test::require(seen.insert(index).second,"no repeated or cyclic links");
        const auto& node=tree.nodes[index];
        if(node.symbol>=0) {
            practice_test::require(static_cast<std::size_t>(node.symbol)<weights.size(),"symbol range");
            ++symbols[node.symbol];
            practice_test::require(node.left==-1 && node.right==-1,"leaf children");
            practice_test::equal(node.weight,weights[node.symbol],"leaf weight"); return node.weight;
        }
        const auto total=validate(node.left)+validate(node.right);
        practice_test::equal(node.weight,total,"parent weight"); return total;
    };
    validate(tree.root);
    practice_test::equal(seen.size(),tree.nodes.size(),"all nodes reachable");
    for(int count:symbols) practice_test::equal(count,1,"each symbol once");
    auto codes=make_codes(tree,static_cast<int>(weights.size()));
    practice_test::equal(codes.size(),weights.size(),"code count");
    if (weights.size()==1) practice_test::equal(codes[0],std::string("0"),"single symbol code");
    long long wpl=0;
    for(std::size_t i=0;i<codes.size();++i) {
        practice_test::require(!codes[i].empty(),"nonempty code");
        for(char bit:codes[i]) practice_test::require(bit=='0'||bit=='1',"binary code");
        wpl+=weights[i]*static_cast<long long>(codes[i].size());
        if (weights.size()>1) {
            int cursor=tree.root;
            for(char bit:codes[i]) {
                practice_test::require(cursor>=0 && static_cast<std::size_t>(cursor)<tree.nodes.size(),"code path index");
                cursor=bit=='0'?tree.nodes[cursor].left:tree.nodes[cursor].right;
            }
            practice_test::require(cursor>=0 && static_cast<std::size_t>(cursor)<tree.nodes.size(),"code ends at existing node");
            practice_test::equal(tree.nodes[cursor].symbol,static_cast<int>(i),"code follows this tree");
        }
        for(std::size_t j=0;j<codes.size();++j) if(i!=j)
            practice_test::require(codes[j].compare(0,codes[i].size(),codes[i])!=0,"prefix-free");
    }
    practice_test::equal(wpl,expected_wpl,"optimal weighted code length");
    std::vector<int> message; std::string bits;
    for(std::size_t i=0;i<codes.size();++i) { message.push_back(static_cast<int>(i)); bits+=codes[i]; }
    message.push_back(0); bits+=codes[0];
    practice_test::equal(decode_bits(tree,bits),message,"encode/decode round trip");
    practice_test::require(decode_bits(tree,"").empty(),"empty encoded message");
    for (const auto& code:codes) if (code.size()>1) {
        bool incomplete_rejected=false;
        try { decode_bits(tree,code.substr(0,code.size()-1)); }
        catch(const std::invalid_argument&) { incomplete_rejected=true; }
        practice_test::require(incomplete_rejected,"incomplete code rejected");
        break;
    }
    bool rejected=false; try { decode_bits(tree,"x"); } catch(const std::invalid_argument&) { rejected=true; }
    practice_test::require(rejected,"invalid bit rejected");
}
int main() { return practice_test::run([] {
    check_huffman({},0);
    check_huffman({5},5);
    check_huffman({1,1,1,1},8);
    check_huffman({45,13,12,16,9,5},224);
}); }
