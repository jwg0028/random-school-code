// Select the button and text elements
const button = document.getElementById('color-button');
const text = document.getElementById('hello-text');

// Add a click event listener to the button
button.addEventListener('click', () => {
    // Generate a random color
    const randomColor = `#${Math.floor(Math.random() * 16777215).toString(16)}`;
    // Change the text color
    text.style.color = randomColor;
});
