import React, { useState } from 'react'

import {
    Card,
    Body2,
    withResize,
} from 'ui-neumorphism'
import Program from './FitnessAppContainers/Program'
import PlanList from './FitnessAppContainers/PlanList'
import FoodList from './FitnessAppContainers/FoodlIst'
import Notifications from './FitnessAppContainers/Notifications'
import Profile from './FitnessAppContainers/Profile'


class FitnessApplication extends React.Component {
   render() {
    const { dark, size } = this.props;
    return (
            <Card flat dark={dark} className='fitness-app-container'>
                <Card flat className='fitness-app-wrapper overflow-hidden'>
                    <Program dark={dark} size={size}/>
                    <PlanList dark={dark} size={size}/>
                    <FoodList dark={dark} size={size}/>
                    <Notifications dark={dark} size={size}/>
                    <Profile dark={dark} size={size}/>
            </Card>
            <Body2 style={{ marginTop: '48px', textAlign: 'center' }}>
            </Body2>
      </Card>
    )
   }
}

export default withResize(FitnessApplication)
