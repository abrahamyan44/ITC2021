import React from 'react';
import { useState, useEffect } from 'react';
import Col from '../src/Col';

function List() {
    const [fetchedData, setFetchedData] = useState([]);

    useEffect(() => {
        fetch('https://datausa.io/api/data?drilldowns=Nation&measures=Population')
            .then(res => res.json())
            .then(res => setFetchedData(res.data))
    })

    return (<table>
        <tbody>
        <Col />
        {fetchedData.map((el, i) => (
                <tr key={i}>
                    <td>{el["ID Nation"]}</td>
                    <td>{el.Nation}</td>
                    <td>{el.Year}</td>
                    <td>{el.Population}</td>
                    <td>{el["Slug Nation"]}</td>
                </tr>
        ))}
        </tbody>
    </table>)
}

export default List;