import React, { useEffect, useState } from 'react';

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
          placeholder='enter food name'
        />
        <button type='submit'>
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
