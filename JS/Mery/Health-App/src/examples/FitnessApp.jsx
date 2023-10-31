import React from 'react'
import Icon from '@mdi/react'
import { mdiPlus } from '@mdi/js'
import {
  H4,
  Card,
  IconButton,
  withResize,
  Subtitle2,
  Caption,
} from 'ui-neumorphism'

import { mdiAccount } from '@mdi/js'
import { ListItem, ListItemGroup } from 'ui-neumorphism'


import FitnessAppScreen from './FitnessAppScreen';
import ProgramScreen from './ProgramScreen';
import PlanScreen from './PlanScreen';
import FoodScreen from './FoodScreen';

class FitnessApp extends React.Component {
  render() {
    const { dark } = this.props

    return (
      <Card flat dark={dark} className='fitness-app-container'>
        <Card
          flat
          className='fitness-app-wrapper overflow-hidden' style={{ justifyContent: 'space-around' }}
        >
          <FitnessAppScreen
            title='Program'
            selectedIndex={0}
            dark={dark}
          >
            <ProgramScreen dark={dark} />
          </FitnessAppScreen>
          <FitnessAppScreen
            title={(
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
            )}
            selectedIndex={1}
            dark={dark}
          >
            <PlanScreen dark={dark} />
          </FitnessAppScreen>
          <FitnessAppScreen
            title='Food'
            selectedIndex={2}
            dark={dark}
          >
            <FoodScreen />
          </FitnessAppScreen>
          <FitnessAppScreen
            title='Notifications'
            selectedIndex={3}
            dark={dark}
          >
            <ListItem
              style={{
                marginTop: '10px',
              }}
              link
              active
              rounded
              title={'Notification 1'}
              subtitle={
                'Do not forget to drink water'
              }
              
            />
            <ListItem
              style={{
                marginTop: '10px',
              }}
              link
              active
              rounded
              title={'Notification 2'}
              subtitle={
                'Please do exercises'
              }
              
            />
            <ListItem
              style={{
                marginTop: '10px',
              }}
              link
              active
              rounded
              title={'Notification 2'}
              subtitle={
                'Please do exercises'
              }
              
            />
            <ListItem
              style={{
                marginTop: '10px',
              }}
              link
              active
              rounded
              title={'Notification 3'}
              subtitle={
                'Running goal is not completed'
              }
              
            />
          </FitnessAppScreen>
          <FitnessAppScreen
            title='Account'
            selectedIndex={4}
            dark={dark}
          >
            <Card
              dark={dark}
              elevation={3}
              style={{
                display: 'flex',
                marginTop: '10px',
                marginBottom: '20px',
                marginLeft: '80px',
                width: '90px',
                height: '90px',
                borderRadius: '30px',
                alignItems: 'center',
                justifyContent: 'center'
              }}
            >
              <Card flat>
                <Icon path={mdiAccount} size={2.5} color='var(--primary)' />
              </Card>
            </Card>
            <Subtitle2>Gender : Female</Subtitle2>
            <Subtitle2>Name : Mery Hovsepyan </Subtitle2>
            <Subtitle2>Weight : 100</Subtitle2>
            <Subtitle2>Height : 200</Subtitle2>
          </FitnessAppScreen>
        </Card>
      </Card>
    )
  }
}

export default withResize(FitnessApp)
