
import './App.css';
import Header from './Header';
import Content from './Content';
import Footer from './Footer';

function App() {
  const someText = ' HELLO ';
  const contentText = 'This is content';
  const footerText = 'This is FOOTER';
  return (
    <div>
      <Header s={someText}/>
      <Content con={contentText} />
      <Footer foo={footerText} />
    </div>
    
  );
}

export default App;
