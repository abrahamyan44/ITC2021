import React from 'react';

export default function Header (props) {
    console.log(props);
    return <div>
        <h1>{props.s} </h1>
        </div>
}