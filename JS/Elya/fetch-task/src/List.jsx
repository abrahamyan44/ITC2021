import React, { useEffect, useState } from 'react';
import './List.css';

function List() {
    const [fetchedData, setFetchedData] = useState([]);

    useEffect(() => {
        fetch('https://datausa.io/api/data?drilldowns=Nation&measures=Population')
            .then(res => res.json())
            .then(res => setFetchedData(res.data))
    })

    return (<div className="list-container">
        <h3>ID Nation</h3>
        { fetchedData.map((el, i) => (
            <li key={i}>
                {el["ID Nation"]}
            </li>
        ))}
        <h3>Nation</h3>
        {fetchedData.map((el) => (
            <li>
                {el.Nation}
            </li>
        ))}
        <h3>ID Year</h3>
        {fetchedData.map((el) => (
            <li>
                {el["ID Year"]}
            </li>
        ))}
        <h3>Year</h3>
        {fetchedData.map((el) => (
            <li>
                {el.Year}
            </li>
        ))}
        <h3>Population</h3>
        {fetchedData.map((el) => (
            <li>
                {el.Population}
            </li>
        ))}
        <h3>Slug Nation</h3>
        {fetchedData.map((el) => (
            <li>
                {el["Slug Nation"]}
            </li>
        ))}
    </div>
    )
}

export default List