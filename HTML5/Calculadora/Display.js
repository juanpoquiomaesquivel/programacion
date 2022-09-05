class Display {
  constructor(displayPreviousValue, displayActualValue) {
    this.displayPreviousValue = displayPreviousValue;
    this.displayActualValue = displayActualValue;
    this.calculator = new Calculator();
    this.previousValue = "";
    this.actualValue = "";
    this.operationType = undefined;
    this.signs = {
      addition: "+",
      subtraction: "-",
      multiplication: "*",
      division: "/",
    };
  }

  clean() {
    this.actualValue = this.actualValue.toString().slice(0, -1);
    this.print();
  }

  cleanAll() {
    this.previousValue = "";
    this.actualValue = "";
    this.operationType = undefined;
    this.print();
  }

  addValue(number) {
    if (number == "." && this.actualValue.includes(".")) return;

    this.actualValue = this.actualValue.toString() + number.toString();
    this.print();
  }

  print() {
    this.displayActualValue.value = this.actualValue;
    this.displayPreviousValue.value = `${this.previousValue} ${this.signs[this.operationType] || ''}`;
  }

  calculate() {
    const previousValue = parseFloat(this.previousValue);
    const actualValue = parseFloat(this.actualValue);

    if (isNaN(previousValue) && isNaN(actualValue)) return;

    this.actualValue = this.calculator[this.operationType](
      previousValue,
      actualValue
    );
  }

  compute(operationType) {
    this.operationType !== '=' && this.calculate();
    this.operationType = operationType;
    this.previousValue = this.actualValue || this.previousValue;
    this.actualValue = "";
    this.print();
  }
}
