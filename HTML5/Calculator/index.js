const displayPreviousValue = document.getElementById("previous-display");
const displayActualValue = document.getElementById("actual-display");
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
    displayContent.compute(button.name);
  });
});
