import React, { useState } from 'react'

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
    mdiFood,
    mdiThemeLightDark,
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
} from 'ui-neumorphism'
import HomePage1 from './FitnessAppContainers/HomePage1'
import HomePage2 from './FitnessAppContainers/HomePage2'
import HomePage3 from './FitnessAppContainers/HomePage3'
import HomePage4 from './FitnessAppContainers/HomePage4'
import HomePage5 from './FitnessAppContainers/HomePage5'


class FitnessApp1 extends React.Component {
   render() {
    const { dark, size } = this.props;
    return (
            <Card flat dark={dark} className='fitness-app-container'>
                <Card flat className='fitness-app-wrapper overflow-hidden'>
                    <HomePage1 dark={dark} size={size}/>
                    <HomePage2 dark={dark} size={size}/>
                    <HomePage3 dark={dark} size={size}/>
                    <HomePage4 dark={dark} size={size}/>
                    <HomePage5 dark={dark} size={size}/>
            </Card>
            <Body2 style={{ marginTop: '48px', textAlign: 'center' }}>
            </Body2>
      </Card>
    )
   }
}

export default withResize(FitnessApp1)
