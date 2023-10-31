const path = require('path');
const CopyPlugin = require("copy-webpack-plugin");


module.exports = {
    mode: "development",
    entry: './src/index.js',
    output: {
        filename: 'bundle.js',
        path: path.resolve(__dirname, 'dist'),
    },
    module: {
        rules: [
            {
                test: /\.css$/i,
                use: ['style-loader', 'css-loader'],
            },
            {
                test: /\.(png|svg|jpg|jpeg|gif)$/i,
                type: 'asset/resource',
            },
        
        ],
    },
    plugins: [
        new CopyPlugin({
          patterns: [
            { from: "src/images", to: "images" },
            { from: "src/index.html", to: "" },
            { from: "src/style.css", to: "" }
          ],
        }),
      ],


};
