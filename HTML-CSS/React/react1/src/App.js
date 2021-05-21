import './App.css';
import Body from './Body';
import Footer from './Footer';
import Header from './Header';


function App() {
  const comp = 'Instigate mobile';
  const cont = 'New opportunities to join Instigate Mobile team in Vanadzor.'
  return (
    <div className="App">
      <Header company = {comp}/>
      <Body context = {cont}/>
      <Footer/>
    </div>
  );
}

export default App;
