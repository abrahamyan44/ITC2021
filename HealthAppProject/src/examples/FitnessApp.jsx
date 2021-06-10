import React, { useEffect, useState } from 'react'

import Icon from '@mdi/react'
import {
  mdiRun,
  mdiYoga,
  mdiPlus,
  mdiHome,
  mdiBell,
  mdiTicket,
  mdiAccount,
  mdiArmFlex,
  mdiDumbbell,
  mdiChartLine,
  mdiChevronRight,
  mdiFace,
  mdiAccountBox
} from '@mdi/js'

import {
  H4,
  H5,
  H6,
  Card,
  Body2,
  Caption,
  Subtitle2,
  IconButton,
  withResize,
  ToggleButton,
  ProgressCircular,
  Fap1
} from 'ui-neumorphism'



function TodoForm({ onAdd }) {
  const [text, setText] = useState("");


  // const [foods,setFoods] = useState(()=>JSON.parse(localStorage.getItem('foods')));

  // useEffect(()=>{
  //   localStorage.setItem('foods',JSON.stringify(foods))
  // },[foods]);

  for (let i = 0; i < localStorage.length; i++) {
    let storedValue = localStorage.key(i);
    console.log(`Item at ${i}: ${storedValue}`);
}


  return (
    <form onSubmit={(e) => {
      e.preventDefault();
      onAdd(text);
      setText("");

    }}
      style={{ display: "flex", justifyContent: "space-between" }}>
      <input type="text" value={text} onChange={(e) => {
        if (e.target.value !== ' ')
          setText(e.target.value);
      }}
      />
      <button >Add</button>
    </form>
  )
}




function TodoItem({ todo, onDelete }) {
  return (
    <div>
      <label style={{
        fill: 'currentcolor',
        display: 'flex',
        width: '252px',
        justifyContent: 'space-between',
      }}>
        <input type="checkbox" />
        {todo.text}
        <button onClick={() => {
          onDelete(todo);
        }}>X</button>
      </label>
    </div>
  )
}


function TodoList({ todos, onDelete, dark }) {
  return (
    <div>
      {
        todos.map((todo) => {
          return (
            <TodoItem dark={dark} key={todo.id}
              todo={todo}
              onDelete={onDelete}
            />
          )

        })
      }
    </div>
  )
}

function App() {

  const [todos, setTodos] = useState([])
  return (
    <div>
      <TodoForm onAdd={(text) => {
        if (text.length !== 0){
          setTodos([
            ...todos,
            {
              id: Math.random(),
              text: text,
            }
          ])
     
        }
      }} />
      <TodoList
        todos={todos}
        onDelete={(todo) => {
          setTodos(todos.filter((t) => t.id !== todo.id));
        }}
      />
    </div>
  )
}


class FitnessApp extends React.Component {

  render() {
    const { dark, size } = this.props


    return (
      <Card flat dark={dark} className='fitness-app-container'>
        <Card flat className='fitness-app-wrapper overflow-hidden'>
          <Card
            rounded
            width={280}
            height={600}
            className={`fitness-app ${size === 'xs' ? 'fitness-app--small' : ''
              } overflow-hidden`}
          >
            <H4 style={{ fontWeight: '500', marginTop: '8px' }}>Program</H4>
            <div
              style={{
                display: 'flex',
                marginTop: '8px',
                justifyContent: 'space-between'
              }}
            >
              <Card
                elevation={2}
                dark={dark}
                style={{ padding: '16px', width: '116px', margin: '16px 0px' }}
              >
                <Card
                  flat
                  style={{
                    width: '32px',
                    height: '32px',
                    marginBottom: '8px',
                    paddingTop: '4px'
                  }}
                >
                  <Icon path={mdiArmFlex} size={1} color='var(--primary)' />
                </Card>
                <Subtitle2>Arm</Subtitle2>
                <Subtitle2 style={{ marginBottom: '8px' }}>training</Subtitle2>
                <Caption secondary>In progress..</Caption>
              </Card>
              <Card
                elevation={2}
                dark={dark}
                style={{ padding: '16px', width: '116px', margin: '16px 0px' }}
              >
                <Card
                  flat
                  style={{
                    width: '32px',
                    height: '32px',
                    marginBottom: '8px',
                    paddingTop: '4px'
                  }}
                >
                  <Icon path={mdiDumbbell} size={1} color='var(--primary)' />
                </Card>
                <Subtitle2>Weight</Subtitle2>
                <Subtitle2 style={{ marginBottom: '8px' }}>training</Subtitle2>
                <Caption secondary>Have finished</Caption>
              </Card>
            </div>
            <div
              style={{
                display: 'flex',
                marginTop: '4px',
                justifyContent: 'space-between'
              }}
            >
              <Card
                elevation={2}
                dark={dark}
                style={{ padding: '16px', width: '116px', margin: '0px' }}
              >
                <Card
                  flat
                  style={{
                    width: '32px',
                    height: '32px',
                    marginBottom: '8px',
                    paddingTop: '4px'
                  }}
                >
                  <Icon path={mdiRun} size={1} color='var(--primary)' />
                </Card>
                <Subtitle2>Run</Subtitle2>
                <Subtitle2 style={{ marginBottom: '8px' }}>training</Subtitle2>
                <Caption secondary>In progress..</Caption>
              </Card>
              <Card
                elevation={2}
                dark={dark}
                style={{ padding: '16px', width: '116px', margin: '0px' }}
              >
                <Card
                  flat
                  style={{
                    width: '32px',
                    height: '32px',
                    marginBottom: '8px',
                    paddingTop: '4px'
                  }}
                >
                  <Icon path={mdiYoga} size={1} color='var(--primary)' />
                </Card>
                <Subtitle2>Yoga</Subtitle2>
                <Subtitle2 style={{ marginBottom: '8px' }}>training</Subtitle2>
                <Caption secondary>No task</Caption>
              </Card>
            </div>
            <H6 style={{ margin: '24px 0px 16px 0px' }}>Courses Collection</H6>
            <Card rounded={false} elevation={2} style={{ padding: '16px' }}>
              <div
                style={{
                  display: 'flex'
                }}
              >
                <Card
                  outlined
                  dark={dark}
                  style={{ padding: '4px', width: '46px', height: '46px' }}
                >
                  <Icon path={mdiTicket} size={1.5} color='var(--primary)' />
                </Card>
                <Card
                  flat
                  dark={dark}
                  style={{ marginLeft: '12px', overflow: 'unset' }}
                >
                  <Subtitle2 style={{ margin: '0px 0px' }}>
                    Courses I attended
                  </Subtitle2>
                  <Card
                    flat
                    style={{
                      display: 'flex',
                      overflow: 'unset',
                      alignItems: 'center'
                    }}
                  >
                    <Caption secondary component='span'>
                      11 courses in total
                    </Caption>
                    <IconButton
                      style={{ marginLeft: '24px' }}
                      text={false}
                      dark={dark}
                      size='small'
                      rounded
                    >
                      <Icon
                        path={mdiChevronRight}
                        size={0.7}
                        color='var(--primary)'
                      />
                    </IconButton>
                  </Card>
                </Card>
              </div>
            </Card>
            <div className='fitness-app-nav-bar'>
              <ToggleButton selected dark={dark}>
                <Icon path={mdiHome} size={0.9} color='var(--primary)' />
              </ToggleButton>
              <ToggleButton dark={dark}>
                <Icon
                  path={mdiChartLine}
                  size={0.8}
                  color={dark ? 'var(--white)' : 'var(--black)'}
                />
              </ToggleButton>

              <ToggleButton dark={dark}>
                <Icon
                  path={mdiChartLine}
                  size={0.8}
                  color={dark ? 'var(--white)' : 'var(--black)'}
                />
              </ToggleButton>


              <ToggleButton dark={dark}>
                <Icon
                  path={mdiBell}
                  size={0.8}
                  color={dark ? 'var(--white)' : 'var(--black)'}
                />
              </ToggleButton>
              <ToggleButton dark={dark}>
                <Icon
                  path={mdiAccount}
                  size={0.9}
                  color={dark ? 'var(--white)' : 'var(--black)'}
                />
              </ToggleButton>
            </div>
          </Card>


          <Card
            rounded
            width={280}
            height={600}
            className={`fitness-app ${size === 'xs' ? 'fitness-app--small' : ''
              } overflow-hidden`}
          >
            <div
              style={{
                display: 'flex',
                marginTop: '8px',
                alignItems: 'center',
                justifyContent: 'space-between'
              }}
            >
              <H4 dark={dark} style={{ fontWeight: '500' }}>
                Plan list
              </H4>
              <IconButton
                size='small'
                rounded
                text={false}
                color='var(--primary)'
                dark={dark}
              >
                <Icon path={mdiPlus} size={0.8} />
              </IconButton>
            </div>
            <div
              style={{
                display: 'flex',
                width: '252px',
                alignItems: 'center',
                justifyContent: 'center'
              }}
            >
              <Card
                dark={dark}
                elevation={3}
                style={{
                  display: 'flex',
                  marginTop: '32px',
                  width: '194px',
                  height: '194px',
                  borderRadius: '150px',
                  alignItems: 'center',
                  justifyContent: 'center'
                }}
              >
                <Card flat>
                  <Icon path={mdiRun} size={2.5} color='var(--primary)' />
                  <H5 style={{ padding: '4px 0px' }}>8,690</H5>

                  <Caption style={{ padding: '4px 0px' }} secondary>
                    Goal: 12k
                  </Caption>
                </Card>
              </Card>
            </div>
            <Card
              rounded={false}
              elevation={3}
              style={{
                display: 'flex',
                padding: '16px',
                marginTop: '36px',
                alignItems: 'center',
                justifyContent: 'space-between'
              }}
            >
              <Card
                flat
                style={{
                  display: 'flex',
                  alignItems: 'center'
                }}
              >
                <Icon path={mdiArmFlex} size={1} color='var(--primary)' />
                <Card flat style={{ marginLeft: '12px' }}>
                  <Subtitle2 style={{ margin: '0px 0px' }}>
                    Completed: 3 group
                  </Subtitle2>
                  <Caption secondary component='span'>
                    Goal: 4 group
                  </Caption>
                </Card>
              </Card>
              <ProgressCircular value={75} color='var(--primary)'>
                75%
              </ProgressCircular>
            </Card>
            <Card
              rounded={false}
              elevation={2}
              style={{
                display: 'flex',
                padding: '16px',
                marginTop: '20px',
                alignItems: 'center',
                justifyContent: 'space-between'
              }}
            >
              <Card
                flat
                style={{
                  display: 'flex',
                  alignItems: 'center'
                }}
              >
                <Icon path={mdiDumbbell} size={1} color='var(--primary)' />
                <Card flat style={{ marginLeft: '12px' }}>
                  <Subtitle2 style={{ margin: '0px 0px' }}>
                    Completed: 6 group
                  </Subtitle2>
                  <Caption secondary component='span'>
                    training
                    Have finished
                    Goal: 6 group
                  </Caption>
                </Card>
              </Card>
              <ProgressCircular value={100} color='var(--primary)'>
                100%
              </ProgressCircular>
            </Card>
            <div className='fitness-app-nav-bar'>
              <ToggleButton dark={dark}>
                <Icon path={mdiHome} size={0.9} />
              </ToggleButton>
              <ToggleButton selected dark={dark} color='var(--primary)'>
                <Icon path={mdiChartLine} size={0.8} />
              </ToggleButton>
              <ToggleButton selected dark={dark} color='var(--primary)'>
                <Icon path={mdiFace} size={0.8} />
              </ToggleButton>
              <ToggleButton dark={dark}>
                <Icon path={mdiBell} size={0.8} />
              </ToggleButton>
              <ToggleButton dark={dark}>
                <Icon path={mdiAccount} size={0.9} />
              </ToggleButton>
            </div>
          </Card>








          <Card
            rounded
            width={280}
            height={600}
            className={`fitness-app ${size === 'xs' ? 'fitness-app--small' : ''
              } overflow-hidden`}
          >
            <div
              style={{
                display: 'flex',
                marginTop: '8px',
                alignItems: 'center',
                justifyContent: 'space-between'
              }}
            >
              <H4 dark={dark} style={{ fontWeight: '500' }}>
                Food List
              </H4>
            </div>
            <Card>
              <App dark={dark} className={`main-topbar`} />

            </Card>

            <div className='fitness-app-nav-bar'>
              <ToggleButton dark={dark}>
                <Icon path={mdiHome} size={0.9} />
              </ToggleButton>
              <ToggleButton selected dark={dark} color='var(--primary)'>
                <Icon path={mdiChartLine} size={0.8} />
              </ToggleButton>
              <ToggleButton selected dark={dark} color='var(--primary)'>
                <Icon path={mdiFace} size={0.8} />
              </ToggleButton>
              <ToggleButton dark={dark}>
                <Icon path={mdiBell} size={0.8} />
              </ToggleButton>
              <ToggleButton dark={dark}>
                <Icon path={mdiAccount} size={0.9} />
              </ToggleButton>
            </div>
          </Card>




          <Card
            rounded
            width={280}
            height={600}
            className={`fitness-app ${size === 'xs' ? 'fitness-app--small' : ''
              } overflow-hidden`}
          >
            <div
              style={{
                display: 'flex',
                marginTop: '8px',
                alignItems: 'center',
                justifyContent: 'space-between'
              }}
            >
              <H4 dark={dark} style={{ fontWeight: '500' }}>
                Profile
              </H4>
            </div>
            <Card>
              <div><i>Contacts</i></div>
              <div><i>Phone</i></div>
              <div><i>favourite</i></div>
              <div><i>Groups</i></div>
            </Card>

            <div className='fitness-app-nav-bar'>
              <ToggleButton dark={dark}>
                <Icon path={mdiHome} size={0.9} />
              </ToggleButton>
              <ToggleButton selected dark={dark} color='var(--primary)'>
                <Icon path={mdiChartLine} size={0.8} />
              </ToggleButton>
              <ToggleButton selected dark={dark} color='var(--primary)'>
                <Icon path={mdiFace} size={0.8} />
              </ToggleButton>
              <ToggleButton dark={dark}>
                <Icon path={mdiBell} size={0.8} />
              </ToggleButton>
              <ToggleButton dark={dark}>
                <Icon path={mdiAccount} size={0.9} />
              </ToggleButton>
            </div>
          </Card>


          <Card
            rounded
            width={280}
            height={600}
            className={`fitness-app ${size === 'xs' ? 'fitness-app--small' : ''
              } overflow-hidden`}
          >
            <div
              style={{
                display: 'flex',
                marginTop: '8px',
                alignItems: 'center',
                justifyContent: 'space-between'
              }}
            >
              <H4 dark={dark} style={{ fontWeight: '500' }}>
                Notifications
              </H4>
            </div>
            <Card style={{ marginTop: "20px" }} >
              <i>2 unreaded notifications</i>

            </Card>

            <div className='fitness-app-nav-bar'>
              <ToggleButton dark={dark}>
                <Icon path={mdiHome} size={0.9} />
              </ToggleButton>
              <ToggleButton selected dark={dark} color='var(--primary)'>
                <Icon path={mdiChartLine} size={0.8} />
              </ToggleButton>
              <ToggleButton selected dark={dark} color='var(--primary)'>
                <Icon path={mdiFace} size={0.8} />
              </ToggleButton>
              <ToggleButton dark={dark}>
                <Icon path={mdiBell} size={0.8} />
              </ToggleButton>
              <ToggleButton dark={dark}>
                <Icon path={mdiAccount} size={0.9} />
              </ToggleButton>
            </div>
          </Card>





        </Card>
        <Body2 style={{ marginTop: '48px', textAlign: 'center' }}>
        </Body2>
      </Card>
    )
  }
}

export default withResize(FitnessApp)