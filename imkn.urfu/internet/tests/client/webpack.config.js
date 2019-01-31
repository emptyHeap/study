const webpack = require('webpack');
const path = require('path');

module.exports = {
  mode: 'development',
  entry: [
    '@babel/polyfill',
    './src/index.js',
//    'webpack-hot-middleware/client',
  ],
  output: {
    path: __dirname + '/dist',
    publicPath: '/',
    filename: 'bundle.js'
  },
  module: {
    rules: [
      {
        test: /\.(js|jsx)$/,
        exclude: /node_modules/,
        use: ['babel-loader']
      }
    ]
  },
  resolve: {
    extensions: ['*', '.js', '.jsx']
  },
  //devtool: 'module-source-map',
  // strange
  devtool: 'cheap-module-source-map',
  // not working
  //devtool: 'cheap-module-eval-source-map',
  //devtool: 'source-map',
  plugins: [
    new webpack.HotModuleReplacementPlugin()
  ],
  devServer: {
    host: '0.0.0.0',
    //publicPath: '/assets/',
    contentBase: path.resolve(__dirname, './views'),
    watchContentBase: true,
    hot: true,
    inline: true,
    historyApiFallback: true,
  }
};
