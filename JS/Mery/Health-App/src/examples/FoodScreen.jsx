import React, { useEffect, useState } from 'react';
import { Button } from 'ui-neumorphism'


const FoodScreen = () => {
  const [foods, setFoods] = useState(() => JSON.parse(localStorage.getItem('foods')) || []);

  const [value, setValue] = useState('');

  useEffect(() => {
    localStorage.setItem('foods', JSON.stringify(foods));
  }, [foods]);

  const handleFoodSubmit = (event) => {
    event.preventDefault();
    setFoods([...foods, value]);
    setValue('');
  };

  return (
    <div>
      <form onSubmit={handleFoodSubmit}>
        <input
          value={value}
          onChange={event => setValue(event.target.value)}
          name='foodName'
          placeholder='Enter food name'
          style={{
            border: 'none',
            width: '100%',
            outline: 'none',
            background: 'none',
            fontSize: '20px',
            color: '#555',
            padding: '10px 10px 20px 5px',
            boxShadow: 'inset 4px 4px 4px #cbced1, inset -4px -4px 4px #ffffff',
          }}
        />
        <button style={{
          background: 'transparent',
          margin: '10px',
          fontSize: '15px',
          borderRadius: '15px',
          height:'30px',
          color:'#2979ff',
          padding: '10px 10px 20px 5px',
          boxShadow: '4px 4px 4px #cbced1, -4px -4px 4px #ffffff',
        }}>
          Submit food
        </button>
      </form>
      <ul>
        {foods.map((food, index) => (
          <li key={`${foods}-${index}`}>
            {food}
          </li>
        ))}
      </ul>
    </div>
  )
};

export default FoodScreen;
