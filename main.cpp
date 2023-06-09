#include <iostream>
#include <bitset>
#include <cstring>


using namespace std;

float binToFloat(string bin) {
    bitset<32> bits(bin);
    float f;
    memcpy(&f, &bits, sizeof(f));
    return f;
}

string floatToBin(float f) {
    bitset<32> bits;
    memcpy(&bits, &f, sizeof(f));
    return bits.to_string();
}

string addBinary(string a, string b) {
    string result = "";
    int carry = 0;

    for (int i = a.length() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 2;
        result = to_string(sum % 2) + result;
    }

    if (carry != 0) {
        result = to_string(carry) + result;
    }

    return result;
}

string multiplyBinary(string a, string b) {
    string result = "0";

    for (int i = b.length() - 1; i >= 0; i--) {
        if (b[i] == '1') {
            result = addBinary(result, a);
        }
        a = a + "0";
    }

    return result;
}

int main() {
    string bin1, bin2;
    cout << "Ingrese dos números binarios en formato IEEE754 de 32 bits  ";
    cin >> bin1 >> bin2;

    float num1 = binToFloat(bin1);
    float num2 = binToFloat(bin2);

    float product = num1 * num2;

    string binProduct = floatToBin(product);

    cout << "Producto: " << binProduct << endl;

    return 0;
}