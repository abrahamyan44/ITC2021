

export default function Book(props) {
    return (
        <>
            <div className='col-md'>
                <p className='author'>
                    {props.author}
                </p>
                <p className='title'>
                    {props.title}
                </p>
                <img src="" alt="book cover"/>
                <div className='button-container'>
                    <button className='buy'>Buy</button>
                    <button className='delete'>Delete</button>
                </div>
            </div>
        </>
    )
}