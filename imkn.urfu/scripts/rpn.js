const variables_data = new Map();
const operands = [ '+', '-', '*', '/', '^', 'sqrt', '(', ')' ]
const operands_priority = {
  '+': 0,
  '-': 0,
  '*': 1,
  '/': 1,
  '^': 2,
  'sqrt': 2,
}
const operands_action = {
  '+': (a, b) => a + b,
  '-': (a, b) => a - b,
  '*': (a, b) => a * b,
  '/': (a, b) => a / b,
  '^': (a, b) => Math.pow(a, b),
  'sqrt': (a, b) => Math.pow(a, 1/b),
}
const mathRe = new RegExp(`\\${operands.join('|\\')}|\\d+(\\.\\d+)?|\\w+`, 'g');

function convert(infix) {
  /**
   * @param infix - уравнение в инфиксном виде
   * @param variables - объёкт с переменными
   *
   * @return уравнение в обратной польской нотации
   */

  //input = infix.split(' ');
  input = infix.match(mathRe)

  let result = [];
  let operands_storage = [];
  for (symbol of input) {
    if (symbol === '(') {
      operands_storage.push(symbol);
    } else if (symbol === ')') {
      while ((last_stored_operand = operands_storage.pop()) != '(') {
        result.push(last_stored_operand);
      }
    } else if (operands.includes(symbol)) {
      let current_operand = symbol;
      let previous_operand = operands_storage.pop();

      if (previous_operand === undefined) {
        operands_storage.push(current_operand);
      } else if (operands_priority[current_operand] <= operands_priority[previous_operand]) {
        result.push(previous_operand);
        operands_storage.push(current_operand);
      } else {
        operands_storage.push(previous_operand);
        operands_storage.push(current_operand)
      }
    } else {
      if (Number(symbol)) {
        result.push(Number(symbol));
      } else {
        result.push(symbol);
      }
    }
    console.log(symbol);
    console.log(operands_storage);
  }

  while (operands_storage.length != 0) {
    result.push(operands_storage.pop());
  }
  //numbers

  return result;
}

function calculate(postfix) {
  /**
   * @param postfix - уравнение в постфиксном виде
   * @param variables - объёкт с переменными
   *
   * @return результат
   */

  const stack = []
  console.log(postfix);

  for (symbol of postfix) {

    if (operands.includes(symbol)) {
      let b = stack.pop();
      let a = stack.pop();

      stack.push(operands_action[symbol](a, b));
      console.log(stack);
    } else {
      if (isNaN(symbol)) {
        console.log('nan', symbol);
        console.log(variables_data);
        stack.push(variables_data.get(symbol));
      } else {
        stack.push(symbol);
      }
      console.log('add',stack);
    }
  }

  return stack.pop();
}

example = 'x + y + z * ( x + y )'
example = 'x+y+x*toc*(lr+z)'
values = {
  'x': 1/100,
  'y': 100,
  'toc': 1,
  'lr': 90,
  'z': 10
}

function renewVariables(variables_list) {
  variablesContainer = document.getElementById('variables');
  variablesContainer.innerHTML = '';
  for (let variable of variables_list) {
    let variableEditor = document.createElement('div');
    variableEditor.classList = ['col-sm-3'];
    variableEditor.classList.add('mt');
    variableEditor.innerHTML = `
      <div class="input-group">
        <span class="input-group-addon">${variable}</span>
        <input class="form-control" placeholder="значение" type="text">
      </div>
      `;
    variablesContainer.appendChild(variableEditor);

    let inputField = variableEditor.getElementsByClassName('form-control')[0];
    if (variables_data.has(variable)) {
      inputField.value = variables_data.get(variable);
    }

    inputField.onchange = () => {
      console.log(inputField);
      console.log(inputField.value);
      console.log(variable, Number(inputField.value), variables_data);
      variables_data.set(variable, Number(inputField.value));
    }
  }
}

window.onload = () => {
  infixField = document.getElementById('infix');
  postfixField = document.getElementById('postfix');
  resultField = document.getElementById('result');
  button = document.getElementById('calculate');

  infixField.onchange = () => {
    re = /[A-Za-z]+/g;
    variables = infixField.value.match(re);
    variables = new Set(variables);
    renewVariables(variables);
  }

  button.onclick = () => {
    converted = convert(infixField.value);
    postfixField.value = converted.join(' ');
    resultField.value = calculate(converted);
  }
}
