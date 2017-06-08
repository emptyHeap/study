window.onload = () => {

  const unencTextArea = document.getElementById('unencoded-text');
  const loadUnencButton = document.getElementById('load-orig');
  const encodeJumpButton = document.getElementById('encode-jump');
  const encodeStopButton = document.getElementById('encode-stop');

  const jumpTextArea = document.getElementById('jump-text');
  const loadJumpButton = document.getElementById('load-jump');
  const decodeJumpButton = document.getElementById('decode-jump');

  const stopTextArea = document.getElementById('stop-text');
  const loadStopButton = document.getElementById('load-stop');
  const decodeStopButton = document.getElementById('decode-stop');


  encodeJumpButton.onclick = () => {
    jumpTextArea.value = encodeJump(unencTextArea.value);
  }
  decodeJumpButton.onclick = () => {
    unencTextArea.value = decodeJump(jumpTextArea.value);
  }

  encodeStopButton.onclick = () => {
    stopTextArea.value = encodeStop(unencTextArea.value);
  }
  decodeStopButton.onclick = () => {
    unencTextArea.value = decodeStop(stopTextArea.value);
  }
}

function encodeJump(string) {
  let encoded = '';
  let array = string.split('').reverse();

  let sequence = [];
  let sequence_size = 0;
  let previous_character;
  let current_character;
  function getNext() {
    previous_character = current_character;
    current_character = array.pop();
    return !!previous_character;
  }
  function saveSequence() {
    encoded += String.fromCodePoint(sequence_size+127);
    encoded += sequence.join('');
    sequence_size = 0;
    sequence = [];
  }
  getNext();
  getNext();

  do {

    if (current_character === previous_character) {
      if (sequence_size < 0) { saveSequence(); }

      if (sequence_size === 0) { sequence = [previous_character]; }
      sequence_size++;
    } else {
      if (sequence_size > 0) {
        saveSequence();
      } else {
        sequence_size--;
        sequence.push(previous_character);
      }
    }
  } while (getNext());
  saveSequence();

  return encoded;
}

function decodeJump(string) {
  let decoded = '';
  let array = string.split('').reverse();

  function decodeChunck() {
    let sequence_size = array.pop().charCodeAt(0) - 127;
    if (sequence_size < 0) {
      while (sequence_size++ != 0) {
        decoded += array.pop();
      }
    } else {
      const character = array.pop();
      decoded += character;
      while (sequence_size-- != 0) {
        decoded += character;
      }
    }
  }

  while (array.length > 0) {
    decodeChunck();
  }

  return decoded;
}

const stop = '#';
function encodeStop(string) {
  let encoded = '';
  let array = string.split('').reverse();

  let current_character;
  let previous_character;
  function getNext() {
    previous_character = current_character;
    current_character = array.pop();
    return !!previous_character  }
  getNext();

  function countSameSymbols() {
    total = 1;
    while (previous_character === current_character
        && total++ < 256
        && getNext()) {};
    return total;
  }

  while (getNext()) {

    let total = countSameSymbols();
    if (total > 3 || previous_character === stop) {
      encoded += `${stop}${String.fromCharCode(total - 1)}${previous_character}`;
    } else {
      while (total-- > 0) {
        encoded += previous_character;
      }
    }
  }

  return encoded;
}

function decodeStop(string) {
  let array = string.split('').reverse();
  let decoded = '';

  let symbol;
  while(symbol = array.pop()) {
    if (symbol === stop) {
      length = array.pop().charCodeAt(0) + 1;
      symbol = array.pop();
      while (length-- != 0) {
        decoded += symbol;
      }
    } else {
      decoded += symbol;
    }
  }

  return decoded;
}
