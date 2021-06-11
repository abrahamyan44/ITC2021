import React from 'react';
import './PlanList.css';
import CompletedPlan from './CompletedPlan/CompletedPlan';
import Group from './Group/Group'
import Icon from '@mdi/react'
import {
  mdiPlus,
  mdiArmFlex,
  mdiDumbbell,
} from '@mdi/js'
import { H4, IconButton } from 'ui-neumorphism'

class PlanList extends React.Component {
    render() {
        const {dark} = this.props;
        return (
            <div>
                <div className='title-and-button'>
                    <H4 dark = {dark} className='title-plan-list'>Plan list</H4>
                    <IconButton size='small' rounded text={false} color='var(--primary)' dark={dark}>
                        <Icon path={mdiPlus} size={1} />
                    </IconButton>
                </div>
                <CompletedPlan dark = {dark}/>
                <div className='two-group'>
                    <Group dark = {dark} 
                        icon = {mdiArmFlex}
                        title = {'Completed: 3 group'}
                        content = {'Goal: 4 group'}
                        procent = {75}
                    />
                    <div style={{height: '20px'}}></div>
                    <Group dark = {dark}
                        icon = {mdiDumbbell}
                        title = {'Completed: 6 group'}
                        content = {'Goal: 6 group'}
                        procent = {100}
                        style={{marginTop: '15px'}}
                    />
                </div>
            </div>
        )
    }
}

export default PlanList;
