import './style.css'

export default function Book(props) {
    return <>
        < div className='book'>
            <img className='image' src={props.image} alt='Book ' />
            <div className='title'>{props.title}</div >
            <div className='author'>{props.author}</div>
        </div >
    </>
};
