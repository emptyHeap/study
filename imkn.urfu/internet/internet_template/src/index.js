function testComponent() {
  let element = document.createElement('div');

  element.innerHTML = ['Hello', 'webpack'].join(' ');

  return element;
}

document.body.appendChild(testComponent());
