import Book from "./Book.jsx";
import "bootstrap/dist/css/bootstrap.min.css";
import "./App.css";

const data = [
  {
    author: "Վարդգես Պետրոսյան",
    title: "Ապրած և չապրած տարիներ",
    img: "https://upload.wikimedia.org/wikipedia/hy/b/b1/%C2%AB%D4%B1%D5%BA%D6%80%D5%A1%D5%AE_%D6%87_%D5%B9%D5%A1%D5%BA%D6%80%D5%A1%D5%AE_%D5%BF%D5%A1%D6%80%D5%AB%D5%B6%D5%A5%D6%80%C2%BB_%D5%A3%D6%80%D6%84%D5%AB_%D5%B7%D5%A1%D5%BA%D5%AB%D5%AF.png",
  },
  {
    author: "Ирвин Ялом",
    title: "Когда ницше плакал",
    img: "https://s1.livelib.ru/boocover/1000120239/o/1e12/Irvin_Yalom__Kogda_Nitsshe_plakal.jpeg",
  },
  {
    author: "J. R. R. Tolkien",
    title: "The Hobbit",
    img: "https://chilternbookshops.co.uk/wp-content/uploads/2020/05/The-Hobbit.jpg",
  },
  {
    author: "Հովհաննես Թումանյան",
    title: "Անբան Հուռի",
    img: "http://www.abrilbooks.com/media/catalog/product/b/2/b204528c-0255-40e4-b546-c7be000ad23c-7.gif",
  },
  {
    author: "Դերենիկ Դեմիրճյան",
    title: "Վարդանանք",
    img: "https://lh3.googleusercontent.com/proxy/IL2DOBfy193Xk8shH091WtYvsHj_utNeO9SagrALof-uBUOUSAhC2qcCeyCbW-LCwTOBDYtFlmf0LuG8UE3PBfuyhnyCUrU0BJyoHg1QFSuS53gu7dm947Aw-VdR75h-O4GqErd_MaffzzEx3BTjCDo",
  },
  {
    author: "Immanuel Kant",
    title: "Critique of Practical Reason",
    img: "http://assets.cambridge.org/97805218/96856/cover/9780521896856.jpg",
  },
  {
    author: "Paulo Coelho",
    title: "Alquimista",
    img: "https://img.wook.pt/images/o-alquimista-paulo-coelho/MXwxNTIzNzEzOXwxMDcyNTQ3NXwxMzgzNTIzMjAwMDAw/500x",
  },
  {
    author: "Վիլյամ Սարոայան",
    title: "Հայրիկ, դու խենթ ես",
    img: "https://i.gr-assets.com/images/S/compressed.photo.goodreads.com/books/1537951793l/42073799._SY475_.jpg",
  },
  {
    author: "Ռեյ Բրեդբըրի",
    title: "Ֆարենհայթ 451",
    img: "https://www.armenpress.am/static/tyyy/ghh/1111/txerq/789/jam/tg/qqqqq/ek/turk/halep/tarvankar/l/123/785/hhggg/rrr/cuyc/oscar/sargis_stepanyan/ddd/despanutyun/armenuhi/qax/451.jpg",
  },
  {
    author: "Ральфом Лейтон",
    title: "Вы, конечно, шутите, мистер Фейнман! ",
    img: "https://images-na.ssl-images-amazon.com/images/I/81R9u2QC30L.jpg",
  },
  {
    author: " Стивена Кови ",
    title: "Семь навыков высокоэффективных людей ",
    img: "https://s1.livelib.ru/boocover/1000712798/200/be77/boocover.jpg",
  },
];

function App() {
  return (
    <div className="App">
      <nav>
        <a href="./App.js">
          <img src="'../public/logo.png" alt="logo" />
        </a>
        <h1 className="little_Tumanyan">Book Store Little Tumanyan</h1>
        <form className="block_container">
          <input
            type="number"
            name="count"
            id="count"
            className="input-bar"
            min="0"
            max="20"
          />
          <button className="submit">Submit</button>
        </form>
      </nav>
      <div className="navBarback"></div>
      <div className="container">
        {data.map((el) => {
          <Book author={el.author} title={el.title}></Book>
        })}
      </div>
    </div>
  );
}

export default App;
