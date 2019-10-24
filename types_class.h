
class Types {
private:
    string typeName;
public:
    void Types();
}

Types::Types() {
    cout << "What type is the monster? ";
    cin >> typeName;
}
