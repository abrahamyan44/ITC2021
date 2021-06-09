const path = require('path');

module.exports = {
  entry: './src/converter.js',
  output: {
    filename: 'main.js',
    path: path.resolve(__dirname, 'dist'),
  },
};