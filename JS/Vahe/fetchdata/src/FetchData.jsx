import React, { useEffect, useState } from 'react';

function renderTableHeader(data) {
    if (data[0] !== undefined) {
        let header = Object.keys(data[0]);
        return header.map((key, index) => {
           return <th key={index}>{key.toUpperCase()}</th>
        })    
    }
}

function renderTableBody(data) {
    console.log(data);
    return data && data.map((country, index) => {
        return (
            <tr key={index}>
                <td>{country['ID Nation']}</td>
                <td>{country['Nation']}</td>
                <td>{country['ID Year']}</td>
                <td>{country['Year']}</td>
                <td>{country['Population']}</td>
                <td>{country['Slug Nation']}</td>
            </tr>
        )
    })
}

function FetchData(props) {
    const [data, setData] = useState([]);
    useEffect(() => {
        fetch('https://datausa.io/api/data?drilldowns=Nation&measures=Population')
            .then(response => response.json())
            .then(res => setData(res.data));
    }, []);
    return (
        <div>
            <h1 id='title'>Fetched data</h1>
            <table id='nation-data'>
                <tbody>
                    <tr>{renderTableHeader(data)}</tr>
                    {renderTableBody(data)}
                </tbody>
            </table>
        </div>
    )
}

export default FetchData;

