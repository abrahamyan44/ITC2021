import React, { useState } from 'react'
import Food from './FoodPage/General'

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
    mdiNotificationClearAll,
    mdiNote,
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


function Notifications({ dark, size }) {
    return (
        <Card flat dark={dark} className='fitness-app-container'>
            <Card flat className='fitness-app-wrapper overflow-hidden'>
                <Card
                    rounded
                    width={300}
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
                        <ToggleButton selected dark={dark} color='var(--primary)'>
                            <Icon path={mdiNotificationClearAll} size={0.8} />
                        </ToggleButton>

                    </div>
                    <div
                        style={{
                            display: 'flex',
                            width: '252px',
                            alignItems: 'center',
                            justifyContent: 'center'
                        }}
                    >
                    </div>
                    <i style={{ marginTop: '20px' }}>65 unreaded notifications</i>
                    <div className='fitness-app-nav-bar'>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiHome} size={0.9} />
                        </ToggleButton>
                        <ToggleButton selected dark={dark} >
                            <Icon path={mdiChartLine} size={0.8} />
                        </ToggleButton>
                        <ToggleButton selected dark={dark} >
                            <Icon path={mdiFood} size={0.8} />
                        </ToggleButton>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiBell} size={0.8} color='var(--primary)' />
                        </ToggleButton>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiAccount} size={0.9} />
                        </ToggleButton>
                    </div>
                </Card>
            </Card>
        </Card>
    )
}

export default Notifications;
