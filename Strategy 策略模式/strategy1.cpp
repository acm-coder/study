
enum TaxBase {
    CN_Tax,
    US_Tax,
    DE_Tax  // 更改
};

class SalesOrder {
    TaxBase tax;

public:
    double CalculateTax() {
        // ...

        if (tax == CN_Tax) {
            // ...
        } else if (tax == US_Tax) {
            // ...
        } else if (tax == DE_Tax) {
            // ...
        } // ... 更改

        // ...
    }
};


