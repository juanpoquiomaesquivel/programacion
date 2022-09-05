const displayPreviousValue = document.getElementById("previousDisplay");
const displayActualValue = document.getElementById("actualDisplay");
const numberButtons = document.querySelectorAll(".number");
const operatorButtons = document.querySelectorAll(".operator");

const displayContent = new Display(displayPreviousValue, displayActualValue);

numberButtons.forEach((button) => {
  button.addEventListener("click", () => {
    displayContent.addValue(button.value);
  });
});

operatorButtons.forEach((button) => {
  button.addEventListener("click", () => {
    displayContent.compute(button.value);
  });
});
